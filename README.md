# Glove Controlled RC Car

![Glove Controlled Car Gif](gcv-small.gif)

*If you're looking to recreate this project then this is not a proper how-to but hopefully it's enough to get you started. I may make an instructable in the future and link it here but for the time being, here's what I have.*

The resources we used are provided below. I may have left some out since I made this repository months after I did the project. It was a great experience making this although it was considered too simple for a major project (ouch!). We made a minimalistic app and test track to accompany the project but I've left those details out. I'm hoping that anyone reading this can use the references and the provided code to recreate this. 

**Note:** My code is slightly different from the ones you'll find in the references since I started from scratch taking bits and pieces from the test programs for the parts and and making it as simplistic as I could. I didn't use a motor shield for the car motors which also affected the code.

## Major Components
1. 2 Arduino Unos
2. 2 nRF24L01 transceivers
3. MPU-6050 acccelerometer/gyroscope

## References
### Inspiration
- Youtube: [nRF24L01 / Accelerometer RC Car](https://www.youtube.com/watch?v=IjUlqe-aeGU)
- Accompanying blog: [nRF24L01 / Accelerometer RC Car](http://forcetronic.blogspot.ae/search?q=Accelerometer+RC+Car)
### Working of transceivers
- YouTube: [1-Day Project: Arduino and nRF24L01+ Data Transceiver](https://www.youtube.com/watch?v=wlhuO82IZjQ)
- Website: [Nrf24L01-2.4GHz-HowTo](http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo)
### Working of accelerometer/gyroscope
- Youtube: [MPU6050 First steps](https://www.youtube.com/watch?v=Z1M1B_719nk)
- Accompanying website: [Arduino – MPU6050 Getting Ready](https://turnsouthat.wordpress.com/2015/07/31/arduino-mpu6050-getting-ready/)
### My code
- [Glove code](glove_code.ino)
- [Vehicle code](vehicle_code.ino)
