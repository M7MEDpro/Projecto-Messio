import 'dart:async';
import 'package:flutter/material.dart';
import 'package:smart_homr/managers/home_Manager.dart';
import 'package:smart_homr/widgets/CustomSwitch.dart';


import '../managers/rooms/room.dart';

import 'CustomAppBar.dart';


class LightingPage extends StatefulWidget {
  final String username;
  const LightingPage({super.key, required this.username});

  @override
  State<LightingPage> createState() => _LightingPageState();
}

class _LightingPageState extends State<LightingPage> {
  final Map<String, Timer> _debounceTimers = {};

  @override
  void initState() {
    super.initState();
    _syncData();
  }

  Future<void> _syncData() async {
    await HomeManager().syncRooms();
    if (mounted) setState(() {});
  }

  @override
  void dispose() {
    for (var timer in _debounceTimers.values) {
      timer.cancel();
    }
    super.dispose();
  }

  void _debounceSetBrightness(String roomName, RoomManager manager, int value) {
    _debounceTimers[roomName]?.cancel();
    _debounceTimers[roomName] = Timer(const Duration(milliseconds: 300), () {
      manager.setBrightness(value);
    });
  }

  Widget buildRoomContainer({
    required String roomName,
    required String imagePath,
    required dynamic roomData,
    required dynamic roomManager,
    required double screenHeight,
    required double screenWidth,
    bool hasMotion = true,
  }) {
    bool isAutoMode = roomData.mode == 2;
    bool isPowerSaving = HomeManager().homeModes.powerSaving;
    double maxBrightness = isPowerSaving ? 30.0 : 100.0;

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
              onLongPress: (){
                 roomManager.setMode(2);
                setState(() {});
              },
              onChanged: isAutoMode
                  ? (_) {}
                  : (value) {
                roomManager.setMode(value ? 1 : 0);
                setState(() {});
              },
              top: screenHeight * 50 / 866,
              left: screenWidth * 231 / 398,
              width: screenWidth * 46 / 398,
              height: screenHeight * 25 / 866,
              fontSize: screenWidth * 9 / 398,
            ),
            if (isAutoMode)
              Positioned(
                top: screenHeight * 50 / 866,
                left: screenWidth * 230 / 398,
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
                    value: isPowerSaving ? 30.0 : roomData.brightness.toDouble(),
                    onChanged: isPowerSaving ? null : (value) {
                      setState(() {
                          
                        if (value > maxBrightness) value = maxBrightness;
                        roomData.brightness = value.toInt();
                      });
                      _debounceSetBrightness(roomName, roomManager, value.toInt());
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
        subtitle: widget.username.toUpperCase(),
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
             
            buildRoomContainer(
              roomName: "OFFICE",
              imagePath: "assets/images/office.png",
              roomData: HomeManager().officeData,
              roomManager: HomeManager().officeManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
             
            buildRoomContainer(
              roomName: "BED ROOM",
              imagePath: "assets/images/bedroom1.png",
              roomData: HomeManager().bedroomData,
              roomManager: HomeManager().bedroomManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
             
            buildRoomContainer(
              roomName: "LIVING ROOM",
              imagePath: "assets/images/living.png",
              roomData: HomeManager().livingData,
              roomManager: HomeManager().livingManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
             
            buildRoomContainer(
              roomName: "GARAGE",
              imagePath: "assets/images/garage.png",
              roomData: HomeManager().garageData,
              roomManager: HomeManager().garageManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
            ),
             
            buildRoomContainer(
              roomName: "YARD",
              imagePath: "assets/images/yard.png",
              roomData: HomeManager().yardData,
              roomManager: HomeManager().yardManager,
              screenHeight: screenHeight,
              screenWidth: screenWidth,
              hasMotion: false,
            ),
          ],
        ),
      ),
    );
  }
}
