import requests
import serial
import json

# Ouvrez la connexion série pour lire les données
ser = serial.Serial('COM3', 9600)

try:
    while True:
        data = ser.readline().decode('utf-8').strip()
        if data:
            # Divisez les données en température et humidité
            temperature, humidity = data.split(',')

            # Créez un dictionnaire JSON avec les données formatées
            json_data = {
                "temperature": temperature,
                "humidity": humidity,
                "auth_token": '69e21081a5b72505b2312b090456e739e254da9b',
            }

            # Effectuez une requête POST pour envoyer les données
            url = "http://127.0.0.1:8000/api/admin/data/"
            response = requests.post(url, json=json_data)

            if response.status_code == 200:
                print("Données envoyées avec succès : ", json_data)
            else:
                print("Échec de l'envoi des données. Code d'état :", response.status_code)
except KeyboardInterrupt:
    # Gérer l'interruption de l'utilisateur (Ctrl+C)
    pass
finally:
    # Fermez la connexion série
    ser.close()
