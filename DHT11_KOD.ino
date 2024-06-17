#include "DHT.h"

#define DHTPIN 2     // DHT11 sensörünün bağlı olduğu pin
#define DHTTYPE DHT11   // Kullanılan DHT sensör tipi

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 sensörü başlatılıyor...");
  dht.begin();
}

void loop() {
  // Ölçüm için sensöre kısa bir süre tanıyın
  delay(2000);

  // Nem ve sıcaklık değerlerini oku
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Eğer okumalar başarısız olursa, hata mesajı yazdır
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Sensör okumaları başarısız!");
    return;
  }

  // Okunan değerleri seri monitöre yazdır
  Serial.print("Nem: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Sıcaklık: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
