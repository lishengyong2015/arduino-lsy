int delay_us = 1000;
int steps = 20;
bool bRun = true;

#define MAX_TICK  7500
#define MIN_TICK  1

typedef struct 
{
  const int level;
  const int step;
}pwm_step;

const pwm_step steplevel[] = 
{
  {1000, 5},
  {1500, 10},
  {2000, 30},
  {3000, 50},
  {4000, 100},
  {5000, 200},
  {6000, 500},
};

#define LEVEL sizeof(steplevel)/sizeof(steplevel[0])

int GetStep(int curLevel)
{
    char i = 0;
    for(i = 0; i < LEVEL; i++)
    {
        if(steplevel[i].level > curLevel)
        {
            return steplevel[i].step;
        }
    }
    return steplevel[LEVEL-1].step;
}

void InitDebug(void)
{  
  Serial.begin(9600);
  Serial.print("start\n");
}

void setup() {
  // put your setup code here, to run once:
  InitDebug();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int numdata = Serial.available();
  if(numdata > 0)
  {
    int read = Serial.read();
    if(read == '0')
    {
      Serial.print("stop\n");
      bRun = false;
    }
    else if(read == '1')
    {
      Serial.print("run\n");
      bRun = true;
    }
    else
    {
      Serial.print("unrec\n");
      Serial.println(read,HEX);
    }
    while(Serial.read()>= 0){}
  }
  if(bRun)
  {
    // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN, HIGH);
    delayMicroseconds(delay_us);
    digitalWrite(LED_BUILTIN, LOW);
    delayMicroseconds(MAX_TICK-delay_us);
    delay_us += steps;
    if(steps > 0)
    {
        steps = GetStep(delay_us);
    }
    else
    {
        steps = -1*GetStep(delay_us);
    }
    if(delay_us > MAX_TICK){
      delay_us=MAX_TICK;
      steps = -1*steps;
    }
    else if(delay_us < MIN_TICK){
      delay_us=MIN_TICK;
      steps = -1*steps;
    }
  }
}
