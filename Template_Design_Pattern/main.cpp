#include <bits/stdc++.h>
using namespace std;

class MLTrainingTemplate {
public:
    virtual ~MLTrainingTemplate() = default;

    void run() { 
        loadData();
        preprocess();
        buildModel();
        train();
        evaluate();
        save();
    }

protected:
    virtual void loadData() = 0;
    virtual void preprocess() = 0;
    virtual void buildModel() = 0;
    virtual void train() = 0;
    virtual void evaluate() = 0;

    virtual void save() {
        cout << "[Save] Persisting model artifacts to disk\n";
    }
};

class ImageClassifierTraining : public MLTrainingTemplate {
protected:
    void loadData() override {
        cout << "[Image] Loading 50k images from dataset path\n";
    }
    void preprocess() override {
        cout << "[Image] Resizing to 224x224, normalizing channels\n";
    }
    void buildModel() override {
        cout << "[Image] Building CNN (Conv-Conv-Pool x3 + FC)\n";
    }
    void train() override {
        cout << "[Image] Training for 10 epochs with Adam lr=1e-3\n";
    }
    void evaluate() override {
        cout << "[Image] Top-1 accuracy on val set: 87%\n";
    }
    void save() override {
        cout << "[Image] Exporting model.onnx and labels.json\n";
    }
};

class TabularRegressorTraining : public MLTrainingTemplate {
protected:
    void loadData() override {
        cout << "[Tabular] Loading CSV with 1M rows\n";
    }
    void preprocess() override {
        cout << "[Tabular] Imputing missing values, one-hot encoding categories\n";
    }
    void buildModel() override {
        cout << "[Tabular] Building Gradient Boosted Trees (depth=6, 500 estimators)\n";
    }
    void train() override {
        cout << "[Tabular] Training with early stopping (patience=20)\n";
    }
    void evaluate() override {
        cout << "[Tabular] RMSE on holdout: 1.32\n";
    }
};

int main() {
    cout << "=== Template Method: ML Training Pipelines ===\n\n";

    ImageClassifierTraining imagePipeline;
    TabularRegressorTraining tabularPipeline;

    cout << "-- Image classifier pipeline --\n";
    imagePipeline.run();

    cout << "\n-- Tabular regressor pipeline --\n";
    tabularPipeline.run();

    return 0;
}
