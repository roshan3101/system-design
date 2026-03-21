# Template Method Pattern – ML Training Pipelines (C++)

Shows how the Template Method pattern fixes the overall workflow for model training while letting concrete pipelines swap in their own steps.

## Classes
- `MLTrainingTemplate` – defines `run()` (load → preprocess → buildModel → train → evaluate → save) and provides a default `save()` hook.
- `ImageClassifierTraining` – custom steps for CNN image training, overrides `save()`.
- `TabularRegressorTraining` – custom steps for tabular regression, inherits default `save()`.

## Running
From `Template_Design_Pattern/`:
```bash
g++ -std=c++17 main.cpp -o main
./main
```
You’ll see both pipelines execute the same high-level algorithm with different concrete behaviors.

## Extension ideas
- Add a `TextTransformerTraining` pipeline.
- Inject logging/metrics by overriding `save()` or inserting hooks.
- Add optional steps (e.g., hyperparameter search) via additional virtual hooks with no-op defaults.

