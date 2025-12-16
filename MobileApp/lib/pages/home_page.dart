import 'package:flutter/material.dart';
import 'package:smart_homr/managers/home_Manager.dart';
import 'package:smart_homr/services/weather_service.dart';

import '../widgets/CustomSwitch.dart';
import '../data/home_Modes_Data.dart';

class HomePage extends StatefulWidget {
  final String username;
  const HomePage({super.key, required this.username});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  HomeManager homeManager = HomeManager();
  HomeModesData homeModes = HomeModesData();

  @override
  void initState() {
    super.initState();
    _syncData();
  }

  Future<void> _syncData() async {
    await homeManager.syncHomeModes();
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    final screenHeight = MediaQuery.of(context).size.height;
    final screenWidth = MediaQuery.of(context).size.width;

    return Scaffold(
      backgroundColor: Colors.white,
      body: Column(
        children: [
          Container(
            width: double.infinity,
            decoration: const BoxDecoration(
              color: Color(0xFFDBE2EF),
            ),
            child: SafeArea(
              child: Padding(
                padding: EdgeInsets.only(
                  top: screenHeight * 0.015,
                  left: screenWidth * 0.05,
                  right: screenWidth * 0.05,
                  bottom: screenHeight * 0.02,
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Container(
                      width: screenWidth * 0.13,
                      height: screenWidth * 0.13,
                      decoration: const BoxDecoration(
                        color: Colors.black,
                        shape: BoxShape.circle,
                      ),
                      child: Icon(
                        Icons.home_rounded,
                        color: Colors.white,
                        size: screenWidth * 0.07,
                      ),
                    ),
                    SizedBox(height: screenHeight * 0.01),
                    Text(
                      'WELCOME HOME',
                      style: TextStyle(
                        fontSize: screenWidth * 0.07,
                        fontWeight: FontWeight.w600,
                        color: Colors.black87,
                        letterSpacing: 0.5,
                      ),
                    ),
                    SizedBox(height: screenHeight * 0.003),
                    Text(
                      widget.username.toUpperCase(),
                      style: TextStyle(
                        fontSize: screenWidth * 0.06,
                        fontWeight: FontWeight.bold,
                        color: Colors.black,
                        letterSpacing: 0.3,
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ),

           
          Expanded(
            child: Container(
              width: double.infinity,
              decoration: BoxDecoration(
                color: const Color(0xFFDBE2EF),
                borderRadius: BorderRadius.only(
                  bottomLeft: Radius.circular(screenWidth * 0.10),
                  bottomRight: Radius.circular(screenWidth * 0.10),
                ),
              ),
              child: Stack(
                clipBehavior: Clip.none,
                children: [
                  SingleChildScrollView(
                    physics: const NeverScrollableScrollPhysics(),
                    padding: EdgeInsets.only(
                      top: screenHeight * 0.02,
                      bottom: screenHeight * 0.02,
                    ),
                    child: Column(
                      children: [
                        SizedBox(height: screenHeight * 0.07),

                         
                        Container(
                          height: screenHeight * 149 / 866,
                          width: screenWidth * 339 / 398,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius: BorderRadius.circular(screenWidth * 24/398),
                          ),
                          child: Stack(
                            children: [
                              Positioned(
                                top: screenHeight * 15 / 866,
                                left: screenWidth * 15 / 398,
                                child: Text(
                                  'WEATHER',
                                  style: TextStyle(
                                    fontSize: screenWidth * 15 / 398,
                                    fontWeight: FontWeight.w900,
                                    color: Colors.black87,
                                  ),
                                ),
                              ),
                              FutureBuilder<double>(
                                future: Weather.getCurrentTemp(),
                                initialData: Weather.lastTemp,
                                builder: (context, asyncSnapshot) {
                                   
                                  double? displayTemp;
                                  if (asyncSnapshot.hasData && asyncSnapshot.data != 0.0) {
                                    displayTemp = asyncSnapshot.data;
                                  }

                                  if (displayTemp != null) {
                                    return Positioned(
                                      top: screenHeight * 49 / 866,
                                      left: screenWidth * 35 / 398,
                                      child: Text(
                                        '$displayTemp°C',
                                        style: TextStyle(
                                          fontSize: screenWidth * 38 / 398,
                                          fontWeight: FontWeight.w300,
                                          color: Colors.black87,
                                        ),
                                      ),
                                    );
                                  }

                                  if (asyncSnapshot.connectionState == ConnectionState.waiting) {
                                    return Positioned(
                                      top: screenHeight * 49 / 866,
                                      left: screenWidth * 35 / 398,
                                      child: Text(
                                        'Loading...',
                                        style: TextStyle(
                                          fontSize: screenWidth * 25 / 398,
                                          fontWeight: FontWeight.w300,
                                          color: Colors.black87,
                                        ),
                                      ),
                                    );
                                  } else if (asyncSnapshot.hasError) {
                                    return Positioned(
                                      top: screenHeight * 49 / 866,
                                      left: screenWidth * 35 / 398,
                                      child: Text(
                                        'Error!',
                                        style: TextStyle(
                                          fontSize: screenWidth * 38 / 398,
                                          fontWeight: FontWeight.w300,
                                          color: Colors.red,
                                        ),
                                      ),
                                    );
                                  } else {
                                      
                                     return Positioned(
                                      top: screenHeight * 49 / 866,
                                      left: screenWidth * 35 / 398,
                                      child: Text(
                                        'Loading...',
                                        style: TextStyle(
                                          fontSize: screenWidth * 25 / 398,
                                          fontWeight: FontWeight.w300,
                                          color: Colors.black87,
                                        ),
                                      ),
                                    );
                                  }
                                },
                              ),
                              Positioned(
                                top: screenHeight * 100 / 866,
                                left: screenWidth * 110 / 398,
                                child: Icon(
                                  Icons.cloud_outlined,
                                  size: screenWidth * 30 / 398,
                                  color: Colors.black87,
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 40 / 866,
                                left: screenWidth * 170 / 398,
                                child: Container(
                                  width: screenWidth * 3 / 398,
                                  height: screenHeight * 70 / 866,
                                  color: const Color(0xFF858585),
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 15 / 866,
                                left: screenWidth * 190 / 398,
                                child: Text(
                                  'ENERGY',
                                  style: TextStyle(
                                    fontSize: screenWidth * 15 / 398,
                                    fontWeight: FontWeight.w900,
                                    color: Colors.black87,
                                  ),
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 30 / 866,
                                left: screenWidth * 190 / 398,
                                child: Text(
                                  'CONSUMPTION',
                                  style: TextStyle(
                                    fontSize: screenWidth * 15 / 398,
                                    fontWeight: FontWeight.w900,
                                    color: Colors.black87,
                                  ),
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 50 / 866,
                                left: screenWidth * 225 / 398,
                                child: Text(
                                  homeModes.powerConsumption.toStringAsFixed(1),
                                  style: TextStyle(
                                    fontSize: screenWidth * 38 / 398,
                                    fontWeight: FontWeight.w300,
                                    color: Colors.black87,
                                  ),
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 95 / 866,
                                left: screenWidth * 283 / 398,
                                child: Icon(
                                  Icons.bolt_sharp,
                                  size: screenWidth * 35 / 398,
                                  color: Colors.black87,
                                ),
                              ),
                            ],
                          ),
                        ),

                        SizedBox(height: screenHeight * 0.025),

                         
                        Row(
                          children: [
                            SizedBox(width: screenWidth * 28 / 398),
                            Container(
                              width: (screenWidth - 2 * screenWidth * 28 / 398 - screenWidth * 20 / 398) / 2,
                              height: screenHeight * 148 / 866,
                              decoration: BoxDecoration(
                                color: Colors.white,
                                borderRadius: BorderRadius.circular(screenWidth * 0.057),
                              ),
                              child: Stack(
                                children: [
                                    CustomSwitch(
                                      value: homeModes.homeAway,
                                      onChanged: (newValue) async {
                                        homeManager.setHomeAway(newValue);
                                        await Future.delayed(const Duration(milliseconds: 200));
                                        _syncData();
                                      },
                                      top: screenHeight * 18 / 866,
                                      left: screenWidth * 80 / 398,
                                      width: screenWidth * 60/398,
                                      height: screenHeight * 30/866,
                                      fontSize: screenWidth * 12 / 398,
                                    ),
                                  Positioned(
                                    bottom: screenHeight * 20 / 866,
                                    left: screenWidth * 15 / 398,
                                    child: Text(
                                      'HOME\nAWAY MODE',
                                      style: TextStyle(
                                        fontSize: screenWidth * 15 / 398,
                                        fontWeight: FontWeight.w900,
                                        color: Colors.black87,
                                        height: 1.2,
                                      ),
                                    ),
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: screenWidth * 20 / 398),
                            Expanded(
                              child: Container(
                                height: screenHeight * 148 / 866,
                                decoration: BoxDecoration(
                                  color: Colors.white,
                                  borderRadius: BorderRadius.circular(screenWidth * 0.057),
                                ),
                                child: Stack(
                                  children: [
                                    CustomSwitch(
                                      value: homeModes.bedTime,
                                      onChanged: (newValue) async {
                                        homeManager.setBedTime(newValue);
                                        await Future.delayed(const Duration(milliseconds: 200));
                                        _syncData();
                                      },
                                      top: screenHeight * 18 / 866,
                                      left: screenWidth * 80 / 398,
                                      width: screenWidth * 60/398,
                                      height: screenHeight * 30/866,
                                      fontSize: screenWidth * 12 / 398,
                                    ),
                                    Positioned(
                                      bottom: screenHeight * 20 / 866,
                                      left: screenWidth * 15 / 398,
                                      child: Text(
                                        'BED\nTIME MODE',
                                        style: TextStyle(
                                          fontSize: screenWidth * 15 / 398,
                                          fontWeight: FontWeight.w900,
                                          color: Colors.black87,
                                          height: 1.2,
                                        ),
                                      ),
                                    ),
                                  ],
                                ),
                              ),
                            ),
                            SizedBox(width: screenWidth * 28 / 398),
                          ],
                        ),

                        SizedBox(height: screenHeight * 0.025),

                         
                        Row(
                          children: [
                            SizedBox(width: screenWidth * 28 / 398),
                            Container(
                              width: (screenWidth - 2 * screenWidth * 28 / 398 - screenWidth * 20 / 398) / 2,
                              height: screenHeight * 148 / 866,
                              decoration: BoxDecoration(
                                color: Colors.white,
                                borderRadius: BorderRadius.circular(screenWidth * 0.057),
                              ),
                              child: Stack(
                                children: [
                                  CustomSwitch(
                                    value: homeModes.powerSaving,
                                    onChanged: (newValue) async {
                                      await homeManager.setPowerSaving(newValue);
                                      await Future.delayed(const Duration(milliseconds: 200));
                                      _syncData();
                                    },
                                    top: screenHeight * 18 / 866,
                                    left: screenWidth * 80 / 398,
                                    width: screenWidth * 60/398,
                                    height: screenHeight * 30/866,
                                    fontSize: screenWidth * 12 / 398,
                                  ),
                                  Positioned(
                                    bottom: screenHeight * 20 / 866,
                                    left: screenWidth * 15 / 398,
                                    child: Text(
                                      'POWER\nSAVING MODE',
                                      style: TextStyle(
                                        fontSize: screenWidth * 15 / 398,
                                        fontWeight: FontWeight.w900,
                                        color: Colors.black87,
                                        height: 1.2,
                                      ),
                                    ),
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: screenWidth * 20 / 398),
                            Expanded(
                              child: Container(
                                height: screenHeight * 148 / 866,
                                decoration: BoxDecoration(
                                  color: Colors.white,
                                  borderRadius: BorderRadius.circular(screenWidth * 0.057),
                                ),
                                child: Stack(
                                  children: [
                                    CustomSwitch(
                                      value: homeModes.emergency,
                                      onChanged: (newValue) async {
                                        homeManager.setEmergency(newValue);
                                        await Future.delayed(const Duration(milliseconds: 200));
                                        _syncData();
                                      },
                                      top: screenHeight * 18 / 866,
                                      left: screenWidth * 80 / 398,
                                      width: screenWidth * 60/398,
                                      height: screenHeight * 30/866,
                                      fontSize: screenWidth * 12 / 398,
                                    ),
                                    Positioned(
                                      bottom: screenHeight * 20 / 866,
                                      left: screenWidth * 15 / 398,
                                      child: Text(
                                        'EMERGENCY\nMODE',
                                        style: TextStyle(
                                          fontSize: screenWidth * 15 / 398,
                                          fontWeight: FontWeight.w900,
                                          color: Colors.black87,
                                          height: 1.2,
                                        ),
                                      ),
                                    ),
                                  ],
                                ),
                              ),
                            ),
                            SizedBox(width: screenWidth * 28 / 398),
                          ],
                        ),

                        SizedBox(height: screenHeight * 0.05),
                      ],
                    ),
                  ),

                   
                  Positioned(
                    left: screenWidth * 0.275,
                    top: screenHeight * -0.0575,
                    child: Image.asset(
                      'assets/images/home.png',
                      height: screenHeight * 0.18,
                    ),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
