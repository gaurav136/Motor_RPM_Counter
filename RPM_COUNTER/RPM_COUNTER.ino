const int ir = 5;
int count=0; 
int irState = 0;
int preState = 0;
float RPM;
unsigned long TimePeriod;
long Period;
bool toggle = false; // for change in ir state
unsigned long initialTime ;
int previousCount;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ir , INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  irState =  digitalRead(ir);
  if (irState == HIGH && preState == 0){
    Serial.print("Time : ");
    TimePeriod = millis();
    Period = TimePeriod - initialTime;
    Serial.println(TimePeriod);
    Serial.println(Period);
    RPM = 60000/(2*Period);
    Serial.print("RPM : ");
    Serial.println(RPM);
    
    count++;
    preState =1;
    
  }
  if(irState == LOW){
    preState = 0;
  }
  
  initialTime = TimePeriod; 
  if(previousCount != count){
    Serial.print("count : ");
    Serial.println(count);
    previousCount = count;
  }
}