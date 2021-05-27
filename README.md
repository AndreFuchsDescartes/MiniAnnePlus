# Hello and welcome to the Mini Anne Plus GitHub

This Project was created as an entry for the 2021 [Trinatronics]( https://www.trirhenatech.eu/lehre/Trinatronics/)  competition.

Our projects aim was to create a low-cost open-source alternative to more expensive commercial CPR dolls. These dolls can be fantastic tools to teach what needs to be done in an emergency. More advanced models feature sensors to provide feedback to the user and can tell you what you need to improve. 
Traditionally however such devices have been too expensive to be wildly used. 
In response to this need the company Laerdal created a low cost low tec CPR doll called [Mini Anne Plus]( https://laerdal.com/products/simulation-training/resuscitation-training/mini-anne-plus/). At a unit cost of only around 40EUR Mini Anne Plus brings CPR training to the masses. 

There is however a caveat. 
Whilst Mini Anne Plus can be used to do CPR training, she is very basic. If you want to train more than just the basics or want simple feedback how well you are performing you won’t get it here. And even worse the “next step up” so to speak costs more than 8x as much. A price that is usually not affordable for those places that really would need access to these kinds of devices. 

This is where we come in. We talked to experts working in the medical field from around the globe, especially in the developing world, and asked them what capabilities they would need to properly train local personnel and civilians. After having spoken to doctors in Mali, South Africa, France, Germany and Switzerland we came up with the following list of features that we wanted to implement:

* Measure and Visualize
 	* CPR
  	* Ventilation
* Simulate
	* Speech
	* Eyes
	* Beat

Of course, the whole project also needed to be as cheap as possible and verry easy to build. That meant we could only use easy to get, low-cost components and very basic manufacturing techniques.
## What we came up with
Introducing Mini Anne Plus 2.0

![Mini Anne ](https://user-images.githubusercontent.com/58589488/119744249-e3696980-be8b-11eb-81fe-7205caaa664f.jpg)

An open-source CPR doll with integrated sensors, simulation capabilities and a dashboard to both monitor your performance and control several symptoms.
She can:
* **Monitor CPR**
* **Measure the frequency of CPR**
* **Monitor the position of the hands during CPR**
* **Give a beat to guide you during CPR (with automatic 2min warning)**
* **Monitor Inflation**
* **Simulate seven different medically accurate eye symptoms**
* **Can simulate speech via a speaker and microphone**
* **Can be controlled and provide feedback via a dashboard**

We achieved all this at a component cost of just 140EUR.
### A closer look
Here we see the first page of the dashboard. Here the measured data from CPR and ventilation is graphed and we get some info on how well we are doing.

![dashboard1](https://user-images.githubusercontent.com/58589488/119741332-c762c980-be85-11eb-80cb-cce3752a4a24.PNG)
This is the settings page from where we can control her eyes, the beat and, if something goes wrong, reset the Arduino.

![dashboard4](https://user-images.githubusercontent.com/58589488/119741351-d0539b00-be85-11eb-8198-fb2659a52575.PNG)

### Parts list
*All these parts are pretty generic. With the exception of the microcontrollers, you can use any parts you like / can get. This list is just a reference of possible parts*

**Mini Anne Plus**
* 1x [Mini Anne Plus]( https://laerdal.com/de/item/103-09023)

**Microcontrollers**
* 1x [ESP32]( https://www.aliexpress.com/item/1005002576730806.html?spm=a2g0o.productlist.0.0.616451a1hDf2wl&algo_pvid=98f58efb-b22f-421e-820f-27ac21793080&algo_expid=98f58efb-b22f-421e-820f-27ac21793080-0&btsid=0bb0623f16217187626974365e9cc1&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [Arduino Mega2560]( https://www.aliexpress.com/item/32850843888.html?spm=a2g0o.productlist.0.0.19f41435qJi87j&algo_pvid=f87d4af4-a2d6-412a-aad6-4be918d5bd04&algo_expid=f87d4af4-a2d6-412a-aad6-4be918d5bd04-0&btsid=0bb0623016217188033187018e5be7&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [Raspberry Pi Zero]( https://www.aliexpress.com/item/1005001993063894.html?spm=a2g0o.productlist.0.0.573d10caEnA6z4&algo_pvid=a11bc4c4-9a1a-4847-9b95-73152e5c596e&algo_expid=a11bc4c4-9a1a-4847-9b95-73152e5c596e-0&btsid=0bb0624416217189114686329e916b&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)

**Sensors & co.**

* 2x [Flex Sensor]( https://www.aliexpress.com/item/4000765691363.html?spm=a2g0o.productlist.0.0.6b1b1986e24SP8&algo_pvid=eaa5e001-3669-43a0-a5ec-69fce4b96f49&algo_expid=eaa5e001-3669-43a0-a5ec-69fce4b96f49-0&btsid=0b0a555916217185720318002e5e80&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 2x [KY-018 Light Sensor]( https://www.aliexpress.com/item/32820189174.html?spm=a2g0o.productlist.0.0.d67f6967REZiWq&algo_pvid=582536c9-685a-444a-94f5-d59cc4fa2a16&algo_expid=582536c9-685a-444a-94f5-d59cc4fa2a16-18&btsid=0b0a555616217186390617356e4cd1&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 2x [TP223 Touch Sensor]( https://www.aliexpress.com/item/4000540638639.html?spm=a2g0o.productlist.0.0.22a76cacFdAZGQ&algo_pvid=e1577a64-cb4f-480a-aa78-50a57f46a108&algo_expid=e1577a64-cb4f-480a-aa78-50a57f46a108-0&btsid=0bb0623916217187282433548e7b5b&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [DFRobot Mini MP3 Player]( https://www.aliexpress.com/item/32502284842.html?spm=a2g0o.productlist.0.0.1b283bb6ETXd7Q&algo_pvid=e2ce3737-6763-4742-9784-f4df649024c7&algo_expid=e2ce3737-6763-4742-9784-f4df649024c7-0&btsid=0b0a555b16217189690997028eea23&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 2x [0.96” OLED Display I2C]( https://www.aliexpress.com/item/32643950109.html?spm=a2g0o.productlist.0.0.103630d54Mk0Ai&algo_pvid=2baab03c-f62a-4261-bcfb-8f2bdf0884d0&algo_expid=2baab03c-f62a-4261-bcfb-8f2bdf0884d0-1&btsid=0b0a556416217191101343227ef0fc&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 2x [8 ohms 3 watt 40mm speakers]( https://www.aliexpress.com/item/32953346815.html?spm=a2g0o.productlist.0.0.2e712b04916n73&algo_pvid=194b94da-0cf6-458a-a945-804c24e37abd&algo_expid=194b94da-0cf6-458a-a945-804c24e37abd-4&btsid=0bb0600116217191684586577ebc6b&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [Wireless microphone headset]( https://www.aliexpress.com/item/4000986863670.html?spm=a2g0o.productlist.0.0.340a7e63DJovHL&algo_pvid=e5171e48-bcb1-4a5f-96e4-7070046a8ed0&algo_expid=e5171e48-bcb1-4a5f-96e4-7070046a8ed0-5&btsid=0b0a556d16217247578725112e6c98&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)

**Consumables**

* 10m [Skin colored medical tape 5cm wide]( https://www.aliexpress.com/item/4001293732726.html?spm=a2g0o.detail.1000014.24.173548c74bAUjD&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.33416.213724.0&scm_id=1007.33416.213724.0&scm-url=1007.33416.213724.0&pvid=53e48b6c-80d4-4c3d-a213-fd232d037655&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.33416.213724.0,pvid:53e48b6c-80d4-4c3d-a213-fd232d037655,tpp_buckets:668%230%23131923%2314_668%23888%233325%235_23416%230%23213724%230_23416%234721%2321967%23670_23416%234722%2321972%238_668%232846%238111%231996_668%235811%2327169%231_668%232717%237560%23209_668%231000022185%231000066058%230_668%233422%2315392%23100_4452%230%23226710%230_4452%233474%2315675%23158_4452%234862%2324463%23881_4452%233098%239624%23952_4452%235108%2323442%23729_4452%233564%2316062%23370)
* 10x [Servo extension cables 1m]( https://www.aliexpress.com/item/4000108934532.html?spm=a2g0o.productlist.0.0.70a239b51W6N66&algo_pvid=2c47440b-b5ef-4437-93ff-8dca9e9f87db&algo_expid=2c47440b-b5ef-4437-93ff-8dca9e9f87db-18&btsid=0bb0622f16217251403626926e3e1f&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 5x [Stepper motor cable 1m]( https://www.aliexpress.com/item/4000905984654.html?spm=a2g0o.productlist.0.0.37c8649ew64V1b&algo_pvid=null&algo_expid=null&btsid=0bb0624516217252040235609efc2c&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 40pcs [Dupont Jumper cables 10cm]( https://www.aliexpress.com/item/4000203371860.html?spm=a2g0o.productlist.0.0.7534610etyhtfL&algo_pvid=4a650d74-3e97-46c6-818d-d3c475b9f16c&algo_expid=4a650d74-3e97-46c6-818d-d3c475b9f16c-0&btsid=0bb0622a16217252625927322ed1c3&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1Set [Resistor kit 1/4W]( https://www.aliexpress.com/item/4000311766184.html?spm=a2g0o.productlist.0.0.5b08692fjTc9Na&algo_pvid=1ceff389-332b-4b78-8b1f-debe6e3e9ff3&algo_expid=1ceff389-332b-4b78-8b1f-debe6e3e9ff3-3&btsid=0b0a555316217253639885430ec35f&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 2x [50V 0.1uF Ceramic capacitor]( https://www.aliexpress.com/item/32875055931.html?spm=a2g0o.detail.1000023.49.2a7f52471Sh4nt)
* 1x [Generic NPN transistor]( https://www.aliexpress.com/item/32845355887.html?spm=a2g0o.productlist.0.0.2a5931fdT503Zv&algo_pvid=585f3982-c87d-424a-a873-f2dc1223a814&algo_expid=585f3982-c87d-424a-a873-f2dc1223a814-1&btsid=0b0a555416217256291863185ed5f4&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [Generic PAM8403 audio amplifier module]( https://www.aliexpress.com/item/32653644096.html?spm=a2g0o.productlist.0.0.3bc51a714G4JOz&algo_pvid=6d376834-5fd0-437f-b5d8-24c626932847&algo_expid=6d376834-5fd0-437f-b5d8-24c626932847-3&btsid=0bb0622d16220738532795397e7553&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [3.5mm audio jack]( https://www.aliexpress.com/item/32712864420.html?spm=a2g0o.productlist.0.0.324063c8WUEiPl&algo_pvid=d8295948-b40c-41c7-948b-390bac66b8d5&algo_expid=d8295948-b40c-41c7-948b-390bac66b8d5-7&btsid=0bb0623a16217258140284144ec28b&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [Generic powerbank]( https://www.aliexpress.com/item/1005001961055558.html?spm=a2g0o.productlist.0.0.242853a8NHUPgX&algo_pvid=6565f8a5-cf35-432c-8a08-9d6b9e1ed8d3&algo_expid=6565f8a5-cf35-432c-8a08-9d6b9e1ed8d3-12&btsid=0bb0624616217258675463350e7fd8&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 2x [Generic Micro SD card]( https://www.aliexpress.com/item/32953910400.html?spm=a2g0o.productlist.0.0.73532958CKJMDD&algo_pvid=c19b6f51-9fcf-4639-a5b8-2feeb5371eb3&algo_expid=c19b6f51-9fcf-4639-a5b8-2feeb5371eb3-8&btsid=0bb0623f16217259230981650e9cf7&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [Arduino Mega shield]( https://www.aliexpress.com/item/1005001919404158.html?spm=a2g0o.productlist.0.0.add765fbQCOigE&algo_pvid=23689952-299e-44ff-9de9-6b65c4a694b4&algo_expid=23689952-299e-44ff-9de9-6b65c4a694b4-0&btsid=0b0a555516220742858421124e06e2&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
* 1x [USB Hub]( https://www.aliexpress.com/item/4001323784281.html?spm=a2g0o.productlist.0.0.79711488UOaHmj&algo_pvid=5ab2a6b3-7e8b-4167-93d5-bbf9a2b3e257&algo_expid=5ab2a6b3-7e8b-4167-93d5-bbf9a2b3e257-36&btsid=0b0a556816220767322553920ecd0a&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)

### Tools 
You will need:
* Soldering Iron
* Hot glue gun
* Side cutter
* Needle nose pliers
* Box Cutter

### How to wire it all up
To connect it all you can follow the schematics provided below. We recommend first building it all on a breadboard and then making a final version on the Arduino Mega shield. All wires should be directly soldered on the final version if possible. This way you avoid unnecessary trouble due to lose or fallen off wires. To safely house the electronics, you will also need any suitable box of your own choosing. It should be approximately 230x160x80mm.

![Pi Zero_bb](https://user-images.githubusercontent.com/58589488/119737575-caf35200-be7f-11eb-870f-fa5bd619f23a.png)

![Eyes_bb](https://user-images.githubusercontent.com/58589488/119737543-be6ef980-be7f-11eb-90b9-a920604eab2b.png)

![Flex Sensors_bb](https://user-images.githubusercontent.com/58589488/119737555-c29b1700-be7f-11eb-9288-8148cc95ccf6.png)

![FlexSensor_schem](https://user-images.githubusercontent.com/58589488/119737567-c75fcb00-be7f-11eb-8425-03861c04c6a0.png)

![MP3Player_bb](https://user-images.githubusercontent.com/58589488/119737568-c9298e80-be7f-11eb-9b20-5896f19be8a3.png)

![Touch Sensors_bb](https://user-images.githubusercontent.com/58589488/119737581-ccbd1580-be7f-11eb-9c83-77c203a49f93.png)

![Voice speaker_bb](https://user-images.githubusercontent.com/58589488/119737586-cdee4280-be7f-11eb-95c0-11e50b23cbbb.png)



## How to build it
First remove the breastplate.
Stick the flex sensor for the lung ON TOP of the lung bag. Use tape to do this and place it in the middle of the bag and orient it such that it runs from where air enter the bag down to the attachment point on the bottom.
Stick the flex sensor for CPR on the bottom of the breastplate. Orient it parallel to the first ridge in the breastplate. This is the one closest to the chin when the plate is mounted.
Glue the two touch sensors into the breastplate directly underneath where the rubber pad is. Note that one has to be glued on the actuating bar that is used to turn the “click” of the CPR on or off. To do this it is important that this bar I in the “on” position and the the air gap in this bar is filled with hot glue before glue in in the sensor **THE SENSOR WILL NOT WORK IF YOU DON’T DO THIS.** Put a dab of glue on the cable where it is soldered onto the sensor as well to provide some strain relief. 
Use tape to stick the beat speaker to the underside of the chest plate.
![Brestplate](https://user-images.githubusercontent.com/58589488/119747846-dfd9e080-be93-11eb-8395-d013e17bf925.JPG)
#### Now the torso is done. Let’s move on to the face.
Remove the face mask.
Place the speech speaker in the middle of the face with the speaker facing towards the face and secure it with tape. Now take the facemask and carefully cut out holes for the eyes with the box cutter. **Make them too small at first it is very easy to get this wrong!** Now mark the position of these holes on the face with a pen. Mount the displays using tape. We made little balls of tape and stuck them under the displays towards the side of the head to orient them better. This gives a more realistic eye impression later on. Now place the light sensors above the eyes so that the sensing module protrudes just a slight bit over the display and secure them with tape.
![Head Closeup](https://user-images.githubusercontent.com/58589488/119748214-b1103a00-be94-11eb-99df-5a2aa024417c.JPG)
![Head Closeup 2](https://user-images.githubusercontent.com/58589488/119748209-aa81c280-be94-11eb-87f1-a5d3126d2ad3.JPG)
Now we are almost done !
Just secure al the wires with some tape. Where they exit Mini Anne you can wrap them in some tape to make a cable. Tuck all the excess away in the box together with all your electronics. **Be careful when using a metal enclosure. If there are sharp edges where the wires enter the box make sure to protect the cables o they can be cut and damaged. Extra layers of tape and a piece of a PET bottle wrapped around the bundle of wires can be used for this** Also a metal enclosure might interfere with your wireless microphone. If this is the case drill a hole in the side of your enclosure and mount the 3.5mm audio jack trough there. This way the receiver can be outside the box.

## The software
We recommend using [PlatformIO]( https://platformio.org/) with [Microsoft Visual Studio Code](https://code.visualstudio.com/) to upload all your code as it can handle all the different microcontrollers used in this project that need to be programmed. A tutorial for setting this up can be found [here.]( https://www.youtube.com/watch?v=0poh_2rBq7E&t=1s)

Upload the code from this repo to the Arduino Mega2560.
The code for the ESP32 can be found [here]()
A copy of our RPi setup can be found [here]()
Copy this image onto your SD card using [Win32Disk Imager](https://sourceforge.net/projects/win32diskimager/files/latest/download)

Connect your controllers to the power bank with the USB hub. Connect the Arduino directly to the Pi.
After plugin in the power bank and waiting for About 2min you should now see a new WiFi appear called “miniannewifi”. Its password is **Insert password here!!**
After connecting you can go to either:
192.168.42.2:1880/ui 
or
192.168.42.3:1880/ui
to access the dashboard. This address might change. If so just check if the other one works. 
**Please only connect with one additional device at a time**

Voila that should be it !

Questions ?

Please contact me at gladius.illuminatus@gmail.com

