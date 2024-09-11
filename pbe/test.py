import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# Carregar o dataset
column_names = [
    'Class',
    'Alcohol',
    'Malic Acid',
    'Ash',
    'Alcalinity of Ash',
    'Magnesium',
    'Total Phenols',
    'Flavanoids',
    'Nonflavanoid Phenols',
    'Proanthocyanins',
    'Color Intensity',
    'Hue',
    'OD280/OD315 of Diluted Wines',
    'Proline'
]

# Carregar o arquivo wine.data
data = pd.read_csv('wine.data', header=None, names=column_names)

# Selecionar apenas as colunas 'Alcohol' e 'Proline' para características
X = data[['Alcohol', 'Proline']]
y = data['Class']

# Dividir os dados em conjuntos de treinamento e teste
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Criar e treinar o modelo de Regressão Logística
model = LogisticRegression(max_iter=1000, multi_class='auto', solver='lbfgs')
model.fit(X_train, y_train)

# Fazer previsões
predictions = model.predict(X_test)

# Calcular a acurácia
accuracy = accuracy_score(y_test, predictions)
print(f'Acurácia: {accuracy:.2f}')

# Matriz de confusão
print("\nMatriz de Confusão:")
print(confusion_matrix(y_test, predictions))

# Relatório de classificação
print("\nRelatório de Classificação:")
print(classification_report(y_test, predictions))
