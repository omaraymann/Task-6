# Task 6.2

## Software Practical Low Pass Filter [LPF]

---

**WALL-E specifications:**

- Encoder has 540 pulses per revolution
- The wheel has 40 cm diameter
- Maximum speed is 0.5 m/s

**To calculate cutoff frequency $fc$ :**

1. Distance of one revolution = $2πr$ = $2*π*0.2$ = $1.256m$
2. now, we need to calculate the time of one revolution
    
    $$
    TIME=DISTANCE/SPEED=1.256/0.5=2.5132 s
    $$
    
3.  1 revolution per 2.5132 sec $≃$  $0.3978$ rev/sec
4. now, we need to calculate number of pulses per second
    
    $$
    540*0.3978=214.86 
    $$
    
5. To calculate in radian per second

$$
(214.86/540)*2π=2.5 rad/sec
$$

### **$fc=214.86$ pulse/sec $=0.3978$ rev/sec=$2.5$ rad/sec**