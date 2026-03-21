# Builder Design Pattern - HTTP Requests

Three variations of the Builder pattern for assembling `HTTPRequest` objects with headers, query params, and optional body data.

## Variants
- `Norma_Builder`: fluent builder with basic validation (URL required, default method GET when missing).
- `Builder_with_director`: separates construction steps from presets via a `HTTPRequestDirector` that creates common GET/POST requests.
- `Step_Builder`: staged interfaces (`URLStep -> MethodStep -> BodyStep -> OptionalStep`) enforce the order of required steps at compile time.

## Build and Run
### Normal fluent builder
```bash
cd Builder_Design_Pattern/Norma_Builder
g++ -std=c++17 -Wall -Wextra -o builder_normal main.cpp
./builder_normal
```

### Builder with director
```bash
cd Builder_Design_Pattern/Builder_with_director
g++ -std=c++17 -Wall -Wextra -o builder_director main.cpp
./builder_director
```

### Step builder
```bash
cd Builder_Design_Pattern/Step_Builder
g++ -std=c++17 -Wall -Wextra -o builder_step main.cpp
./builder_step
```

## Expected Outputs
### Normal fluent builder
```
Executing HTTP Request:
URL: https://api.example.com/data
Method: POST
Body: {"key": "value"}
Headers:
Content-Type: application/json
Query Parameters:
version: 1.0
```

### Builder with director
```
Executing HTTP Request:
URL: https://api.example.com/data
Method: GET

Executing HTTP Request:
URL: https://api.example.com/data
Method: POST
Body: {"name": "John"}
```

### Step builder
```
Executing HTTP Request:
URL: https://api.example.com/data
Method: POST
Body: {"key": "value"}
Headers:
Content-Type: application/json
Query Parameters:
version: 1.0
```

## Notes
- All variants keep object creation readable by chaining calls instead of long constructors.
- The director centralizes canned request recipes; the step builder prevents missing required fields by design.
- For production use, add validation (e.g., require method in step builder) and consider `std::unordered_map` if header ordering is irrelevant.
