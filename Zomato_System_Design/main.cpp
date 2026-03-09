#include <iostream>
#include <vector>

#include "factories/NowOrderFactory.h"
#include "managers/OrderManager.h"
#include "managers/RestrauntManager.h"
#include "services/NotificationService.h"
#include "strategies/UPIPaymentStrategy.h"

using namespace std;

int main()
{
    // Seed data
    RestrauntManager restrauntManager;
    OrderManager orderManager;

    Restaurant* r1 = restrauntManager.addRestaurant("Spice Garden", "Bangalore");
    r1->addMenuItem(new MenuItem("M1", "Paneer Biryani", 240));
    r1->addMenuItem(new MenuItem("M2", "Veg Thali", 180));

    Restaurant* r2 = restrauntManager.addRestaurant("Burger Hub", "Mumbai");
    r2->addMenuItem(new MenuItem("B1", "Classic Burger", 160));
    r2->addMenuItem(new MenuItem("B2", "Cheese Burger", 220));

    // User comes
    User user(1, "Riya", "HSR Layout, Bangalore");
    cout << "User: " << user.getName() << " (" << user.getAddress() << ")\n";

    // Search by location
    string location = "bangalore";
    vector<Restaurant*> matched = restrauntManager.searchByLocation(location);
    if (matched.empty())
    {
        cout << "No restaurants found for location: " << location << endl;
        return 0;
    }

    cout << "\nRestaurants found in " << location << ":\n";
    for (size_t i = 0; i < matched.size(); ++i)
    {
        cout << i + 1 << ". " << matched[i]->getName() << " (" << matched[i]->getLocation() << ")\n";
    }

    // Select one restaurant
    Restaurant* selected = matched[0];
    cout << "\nSelected restaurant: " << selected->getName() << endl;

    // List menu
    cout << "Menu:\n";
    for (auto* item : selected->getMenuItems())
    {
        cout << " - " << item->getCode() << " | " << item->getName() << " | Rs " << item->getPrice() << endl;
    }

    // Add item to cart
    Cart* cart = user.getCart();
    cart->setRestaurant(selected);
    MenuItem* chosenItem = selected->findMenuItemByCode("M1");
    if (!chosenItem)
    {
        cout << "Item not found.\n";
        return 0;
    }
    cart->addItem(chosenItem);
    cout << "\nAdded to cart: " << chosenItem->getName() << endl;

    // Payment + Order creation
    NowOrderFactory nowFactory;
    Order* order = nowFactory.createOrder(
        1001,
        &user,
        cart,
        selected,
        cart->getItems(),
        new UPIPaymentStrategy("riya@upi"),
        "Delivery");

    if (!order->processPayment())
    {
        cout << "Payment failed.\n";
        delete order;
        return 0;
    }

    // Order completed + notify
    orderManager.addOrder(order);
    cout << "\nOrder completed successfully.\n";
    NotificationService::notify(order);
    orderManager.listOrder();

    return 0;
}
