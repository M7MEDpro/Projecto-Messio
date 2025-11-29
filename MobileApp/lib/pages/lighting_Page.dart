import 'package:flutter/material.dart';
import 'package:smart_homr/Widgets/CustomSwitch.dart';
import 'CustomAppBar.dart';
import 'NavigationBar.dart';

class LightingPage extends StatefulWidget {
  const LightingPage({super.key});

  @override
  State<LightingPage> createState() => _LightingPageState();
}

bool OfficeLighting = false;
bool OfficeDaylight = false;
bool OfficeMotion = false;
bool bedRoom1Lighting = false;
bool bedRoom1Daylight = false;
bool bedRoom1Motion = false;
bool LivingLighting = false;
bool LivingDaylight = false;
bool LivingMotion = false;
bool garageLighting = false;
bool garageDaylight = false;
bool garageMotion = false;
bool yardLighting = false;
bool yardDaylight = false;
int OfficeBrightness = 0;
int LivingBrightness = 0;
int BedRoom1Brightness = 0;
int GarageBrightness = 0;
int YardBrightness = 0;

class _LightingPageState extends State<LightingPage> {
  Widget buildRoomContainer({
    required String roomName,
    required String imagePath,
    required bool lightingValue,
    required bool daylightValue,
    required bool motionValue,
    required int brightnessValue,
    required Function(bool) onLightingChanged,
    required Function(bool) onDaylightChanged,
    required Function(bool) onMotionChanged,
    required Function(double) onBrightnessChanged,
    required double screenHeight,
    required double screenWidth,
  }) {
    return Padding(
      padding: EdgeInsets.symmetric(
        vertical: screenHeight * 18 / 866,
        horizontal: screenWidth * 25 / 398,
      ),
      child: Container(
        height: screenHeight * 175 / 866,
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.all(
            Radius.circular(screenWidth * 24 / 398),
          ),
        ),
        child: Stack(
          children: [
            Positioned(
              top: screenHeight * 15 / 866,
              left: screenWidth * 30 / 398,
              child: Text(
                roomName,
                style: TextStyle(
                  fontSize: screenWidth * 13 / 398,
                  fontWeight: FontWeight.w900,
                  color: Colors.black87,
                ),
              ),
            ),
            Positioned(
              top: screenHeight * 56 / 866,
              left: screenWidth * 148 / 398 * 1.1,
              child: Text(
                "Lighting",
                style: TextStyle(
                  fontSize: screenWidth * 13 / 398,
                  fontWeight: FontWeight.w600,
                  color: Colors.black87,
                ),
              ),
            ),
            Positioned(
              top: screenHeight * 97 / 866,
              left: screenWidth * 148 / 398 * 1.1,
              child: Text(
                "Daylight",
                style: TextStyle(
                  fontSize: screenWidth * 13 / 398,
                  fontWeight: FontWeight.w600,
                  color: Colors.black87,
                ),
              ),
            ),
            Positioned(
              top: screenHeight * 140 / 866,
              left: screenWidth * 148 / 398 * 1.1,
              child: Text(
                "Motion",
                style: TextStyle(
                  fontSize: screenWidth * 13 / 398,
                  fontWeight: FontWeight.w600,
                  color: Colors.black87,
                ),
              ),
            ),
            CustomSwitch(
              value: lightingValue,
              onChanged: onLightingChanged,
              top: screenHeight * 50 / 866,
              left: screenWidth * 231 / 398,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              width: screenWidth * 46 / 398,
              height: screenHeight * 25 / 866,
              fontSize: screenWidth * 9 / 398,
            ),
            CustomSwitch(
              value: daylightValue,
              onChanged: onDaylightChanged,
              top: screenHeight * 88 / 866,
              left: screenWidth * 231 / 398,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              width: screenWidth * 46 / 398,
              height: screenHeight * 25 / 866,
              fontSize: screenWidth * 9 / 398,
            ),
            CustomSwitch(
              value: motionValue,
              onChanged: onMotionChanged,
              top: screenHeight * 130 / 866,
              left: screenWidth * 231 / 398,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              width: screenWidth * 46 / 398,
              height: screenHeight * 25 / 866,
              fontSize: screenWidth * 9 / 398,
            ),
            Positioned(
              top: screenHeight * 38 / 866,
              left: screenWidth * 15 / 398,
              child: ClipRRect(
                borderRadius: BorderRadius.circular(screenWidth * 0.06),
                child: Image.asset(
                  imagePath,
                  width: screenWidth * 124 / 398,
                  fit: BoxFit.cover,
                ),
              ),
            ),
            Positioned(
              top: screenHeight * 38 / 866,
              bottom: screenHeight * 15 / 866,
              left: screenWidth * 315 / 398,
              child: RotatedBox(
                quarterTurns: 3,
                child: SliderTheme(
                  data: SliderTheme.of(context).copyWith(
                    activeTrackColor: Color(0xFF67B8C6),
                    inactiveTrackColor: Color(0xFF000000),
                    thumbColor: Color(0xFF56C6DC),
                    overlayColor: Color(0xFF5AB4AC).withOpacity(0.1),
                    trackHeight: screenHeight * 2 / 866,
                    thumbShape: RoundSliderThumbShape(
                        enabledThumbRadius: screenHeight * 4 / 866),
                    overlayShape: RoundSliderOverlayShape(
                        overlayRadius: screenHeight * 8 / 866),
                  ),
                  child: Slider(
                    value: brightnessValue.toDouble(),
                    onChanged: onBrightnessChanged,
                    min: 0.0,
                    max: 100.0,
                  ),
                ),
              ),
            )
          ],
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    final screenHeight = MediaQuery.of(context).size.height;
    final screenWidth = MediaQuery.of(context).size.width;

    return Scaffold(
      backgroundColor: Colors.white,
      appBar: CustomAppBar(
        title: "WELCOME HOME",
        subtitle: "ABDO",
        height: screenHeight * 0.20,
      ),
      body: Container(
        width: double.infinity,
        decoration: BoxDecoration(
          color: const Color(0xFFDBE2EF),
          borderRadius: BorderRadius.only(
            bottomLeft: Radius.circular(screenWidth * 0.10),
            bottomRight: Radius.circular(screenWidth * 0.10),
          ),
        ),
        child: ListView(
          children: [
            // Office
            buildRoomContainer(
              roomName: "OFFICE",
              imagePath: "assets/images/office.png",
              lightingValue: OfficeLighting,
              daylightValue: OfficeDaylight,
              motionValue: OfficeMotion,
              brightnessValue: OfficeBrightness,
              onLightingChanged: (value) {
                setState(() {
                  OfficeLighting = value;
                });
              },
              onDaylightChanged: (value) {
                setState(() {
                  OfficeDaylight = value;
                });
              },
              onMotionChanged: (value) {
                setState(() {
                  OfficeMotion = value;
                });
              },
              onBrightnessChanged: (value) {
                setState(() {
                  OfficeBrightness = value.toInt();
                });
              },
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
            // Bed Room
            buildRoomContainer(
              roomName: "BED ROOM",
              imagePath: "assets/images/bedroom1.png",
              lightingValue: bedRoom1Lighting,
              daylightValue: bedRoom1Daylight,
              motionValue: bedRoom1Motion,
              brightnessValue: BedRoom1Brightness,
              onLightingChanged: (value) {
                setState(() {
                  bedRoom1Lighting = value;
                });
              },
              onDaylightChanged: (value) {
                setState(() {
                  bedRoom1Daylight = value;
                });
              },
              onMotionChanged: (value) {
                setState(() {
                  bedRoom1Motion = value;
                });
              },
              onBrightnessChanged: (value) {
                setState(() {
                  BedRoom1Brightness = value.toInt();
                });
              },
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
            // Living Room
            buildRoomContainer(
              roomName: "LIVING ROOM",
              imagePath: "assets/images/living.png",
              lightingValue: LivingLighting,
              daylightValue: LivingDaylight,
              motionValue: LivingMotion,
              brightnessValue: LivingBrightness,
              onLightingChanged: (value) {
                setState(() {
                  LivingLighting = value;
                });
              },
              onDaylightChanged: (value) {
                setState(() {
                  LivingDaylight = value;
                });
              },
              onMotionChanged: (value) {
                setState(() {
                  LivingMotion = value;
                });
              },
              onBrightnessChanged: (value) {
                setState(() {
                  LivingBrightness = value.toInt();
                });
              },
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
            // Garage
            buildRoomContainer(
              roomName: "GARAGE",
              imagePath: "assets/images/garage.png",
              lightingValue: garageLighting,
              daylightValue: garageDaylight,
              motionValue: garageMotion,
              brightnessValue: GarageBrightness,
              onLightingChanged: (value) {
                setState(() {
                  garageLighting = value;
                });
              },
              onDaylightChanged: (value) {
                setState(() {
                  garageDaylight = value;
                });
              },
              onMotionChanged: (value) {
                setState(() {
                  garageMotion = value;
                });
              },
              onBrightnessChanged: (value) {
                setState(() {
                  GarageBrightness = value.toInt();
                });
              },
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
            // Yard
            buildRoomContainer(
              roomName: "YARD",
              imagePath: "assets/images/yard.png",
              lightingValue: yardLighting,
              daylightValue: yardDaylight,
              motionValue: false, // Yard doesn't have motion sensor in your design
              brightnessValue: YardBrightness,
              onLightingChanged: (value) {
                setState(() {
                  yardLighting = value;
                });
              },
              onDaylightChanged: (value) {
                setState(() {
                  yardDaylight = value;
                });
              },
              onMotionChanged: (value) {
                // Yard doesn't have motion sensor
              },
              onBrightnessChanged: (value) {
                setState(() {
                  YardBrightness = value.toInt();
                });
              },
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
          ],
        ),
      ),
    );
  }
}