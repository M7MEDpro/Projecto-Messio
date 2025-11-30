import 'dart:async';
import 'package:flutter/material.dart';
import 'package:smart_homr/Widgets/CustomSwitch.dart';

import '../data/rooms/office_room.dart';
import '../data/rooms/bedroom_room.dart';
import '../data/rooms/living_room.dart';
import '../data/rooms/garage_room.dart';
import '../data/rooms/yard_room.dart';

import '../managers/rooms/office_room.dart';
import '../managers/rooms/bedroom_room_manager.dart';
import '../managers/rooms/living_room_manager.dart';
import '../managers/rooms/garage_room_manager.dart';
import '../managers/rooms/yard_room_manager.dart';

import 'CustomAppBar.dart';

// Initialize all room data
OfficeRoomData officeData = OfficeRoomData();
BedroomRoomData bedroomData = BedroomRoomData();
LivingRoomData livingData = LivingRoomData();
GarageRoomData garageData = GarageRoomData();
YardRoomData yardData = YardRoomData();

// Initialize all room managers
OfficeRoomManager officeManager = OfficeRoomManager(officeData);
BedroomRoomManager bedroomManager = BedroomRoomManager(bedroomData);
LivingRoomManager livingManager = LivingRoomManager(livingData);
GarageRoomManager garageManager = GarageRoomManager(garageData);
YardRoomManager yardManager = YardRoomManager(yardData);

class LightingPage extends StatefulWidget {
  const LightingPage({super.key});

  @override
  State<LightingPage> createState() => _LightingPageState();
}

class _LightingPageState extends State<LightingPage> {
  Timer? _officeTimer;
  Timer? _bedroomTimer;
  Timer? _livingTimer;
  Timer? _garageTimer;
  Timer? _yardTimer;

  @override
  void dispose() {
    _officeTimer?.cancel();
    _bedroomTimer?.cancel();
    _livingTimer?.cancel();
    _garageTimer?.cancel();
    _yardTimer?.cancel();
    super.dispose();
  }

  void _debounceBrightness(Timer? timer, Function(int) setBrightness, int value) {
    timer?.cancel();
    timer = Timer(const Duration(milliseconds: 300), () {
      setBrightness(value);
    });
  }

  Widget buildRoomContainer({
    required String roomName,
    required String imagePath,
    required dynamic roomData,
    required dynamic roomManager,
    required double screenHeight,
    required double screenWidth,
    required Timer? brightnessTimer,
    required Function(Timer?) onTimerUpdate,
    bool hasMotion = true,
  }) {
    bool isAutoMode = roomData.mode == 2;

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
                  color: isAutoMode ? Colors.black38 : Colors.black87,
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
            if (hasMotion)
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
              value: roomData.mode == 1,
              onChanged: isAutoMode
                  ? (_) {}
                  : (value) {
                roomManager.setMode(value ? 1 : 0);
                setState(() {});
              },
              top: screenHeight * 50 / 866,
              left: screenWidth * 231 / 398,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              width: screenWidth * 46 / 398,
              height: screenHeight * 25 / 866,
              fontSize: screenWidth * 9 / 398,
            ),
            if (isAutoMode)
              Positioned(
                top: screenHeight * 50 / 866,
                left: screenWidth * 237 / 398,
                child: Container(
                  width: screenWidth * 50 / 398,
                  height: screenHeight * 30 / 866,
                  decoration: BoxDecoration(
                    color: Colors.white.withOpacity(0.7),
                    borderRadius: BorderRadius.circular(screenWidth * 20 / 398),
                  ),
                ),
              ),
            CustomSwitch(
              value: roomData.daylight,
              onChanged: (value) {
                roomManager.setDaylight(value);
                setState(() {});
              },
              top: screenHeight * 88 / 866,
              left: screenWidth * 231 / 398,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              width: screenWidth * 46 / 398,
              height: screenHeight * 25 / 866,
              fontSize: screenWidth * 9 / 398,
            ),
            if (hasMotion)
              CustomSwitch(
                value: roomData.motion,
                onChanged: (value) {
                  roomManager.setMotion(value);
                  setState(() {});
                },
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
                    value: roomData.brightness.toDouble(),
                    onChanged: (value) {
                      setState(() {
                        roomData.brightness = value.toInt();
                      });

                      brightnessTimer?.cancel();
                      onTimerUpdate(Timer(const Duration(milliseconds: 300), () {
                        roomManager.setBrightness(value.toInt());
                      }));
                    },
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
              roomData: officeData,
              roomManager: officeManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              brightnessTimer: _officeTimer,
              onTimerUpdate: (timer) => _officeTimer = timer,
            ),
            // Bed Room
            buildRoomContainer(
              roomName: "BED ROOM",
              imagePath: "assets/images/bedroom1.png",
              roomData: bedroomData,
              roomManager: bedroomManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              brightnessTimer: _bedroomTimer,
              onTimerUpdate: (timer) => _bedroomTimer = timer,
            ),
            // Living Room
            buildRoomContainer(
              roomName: "LIVING ROOM",
              imagePath: "assets/images/living.png",
              roomData: livingData,
              roomManager: livingManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              brightnessTimer: _livingTimer,
              onTimerUpdate: (timer) => _livingTimer = timer,
            ),
            // Garage
            buildRoomContainer(
              roomName: "GARAGE",
              imagePath: "assets/images/garage.png",
              roomData: garageData,
              roomManager: garageManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              brightnessTimer: _garageTimer,
              onTimerUpdate: (timer) => _garageTimer = timer,
            ),
            // Yard (no motion sensor)
            buildRoomContainer(
              roomName: "YARD",
              imagePath: "assets/images/yard.png",
              roomData: yardData,
              roomManager: yardManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              hasMotion: false,
              brightnessTimer: _yardTimer,
              onTimerUpdate: (timer) => _yardTimer = timer,
            ),
          ],
        ),
      ),
    );
  }
}