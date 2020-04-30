void setup() {
  Serial.begin(9600);
}

void loop() {
  int rssi = 0;

#if Wiring_WiFi == 1
  rssi = WiFi.RSSI();
#elif Wiring_Cellular == 1
  CellularSignal sig = Cellular.RSSI();
  rssi = sig.rssi;
#endif
  if (rssi < 0) {
    if  (rssi>=-70){Serial.println("Excellent"); }
    else if(rssi>=-70 && rssi >-85) {Serial.println("Good");}
    else if (rssi>-86&& rssi >=-100) {Serial.println("Fair");}
    else if (rssi>-100) {Serial.println("Poor");}
    else if (rssi>-110) {Serial.println("No Signal");}
  }
  delay(1000);
}
