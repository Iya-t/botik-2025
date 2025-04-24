const int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("🟢 Arduino готово");
}

void loop() {
  if (Serial.available()) {
    // Прочитай всё, что пришло
    String input = Serial.readStringUntil('\n');
    input.trim();

    // Просто факт того, что данные пришли — включаем лампу
    Serial.println("📥 Что-то получено: " + input);

    // Мигаем!
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    Serial.println("💡 Лампа мигнула");
  }
}
