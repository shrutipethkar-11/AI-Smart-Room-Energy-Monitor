# AI-Based Energy Anomaly Detection
# Detects unusual room energy consumption

from sklearn.ensemble import IsolationForest

# Sample energy consumption data in watts
energy_data = [
    [120], [125], [118], [130], [127],
    [122], [129], [124], [126], [121],
    [128], [123], [126], [131],
    [450], [465], [440]
]
# Create AI anomaly detection model
model = IsolationForest(
    contamination=0.15,
    random_state=42
)

# Train the model
model.fit(energy_data)

# Predict normal and abnormal readings
predictions = model.predict(energy_data)

print("Energy Usage Analysis")
print("---------------------")

for value, prediction in zip(energy_data, predictions):

    if prediction == -1:
        print(value[0], "W -> ANOMALY")
    else:
        print(value[0], "W -> NORMAL")
