import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
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
            decoration: BoxDecoration(
              color: const Color(0xFFDBE2EF),
              borderRadius: BorderRadius.only(

              ),
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
                  mainAxisAlignment: MainAxisAlignment.start,
                  mainAxisSize: MainAxisSize.min,
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
                    // TITLE
                    Text(
                      'WELCOME HOME',
                      style: TextStyle(
                        fontSize: screenWidth * 0.07,
                        fontWeight: FontWeight.w600,
                        color: Colors.black87,
                        letterSpacing: 0.5,
                      ),
                      overflow: TextOverflow.visible,
                      maxLines: 2,
                    ),
                    SizedBox(height: screenHeight * 0.003),
                    // SUBTITLE
                    Text(
                      'ABDO',
                      style: TextStyle(
                        fontSize: screenWidth * 0.06,
                        fontWeight: FontWeight.bold,
                        color: Colors.black,
                        letterSpacing: 0.3,
                      ),
                      overflow: TextOverflow.ellipsis,
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
                    padding: EdgeInsets.only(
                      top: screenHeight * 0.02,
                      bottom: screenHeight * 0.02,
                    ),
                    child: Column(
                      children: [
                        SizedBox(height: screenHeight * 0.07),
                        // Big container
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
                                    fontWeight: FontWeight.bold,
                                    color: Colors.black87,
                                  ),
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 50 / 866,
                                left: screenWidth * 50 / 398,
                                child: Text(
                                  '33',
                                  style: TextStyle(
                                    fontSize: screenWidth * 38 / 398,
                                    fontWeight: FontWeight.w300,
                                    color: Colors.black87,
                                  ),
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 95 / 866,
                                left: screenWidth * 105 / 398,
                                child: Icon(
                                  Icons.cloud_outlined,
                                  size: screenWidth * 30 / 398,
                                  color: Colors.black87,
                                ),
                              ),
                              Positioned(
                                top: screenHeight * 95 / 866,
                                left: screenWidth * 105 / 398,
                                child: Container(
                                  width: screenWidth * 3 / 398,
                                  height: screenHeight * 70/866,
                                  color: Color(0xFF858585),
                               ),

                              ),
                            ],
                          ),
                        ),
                        SizedBox(height: screenHeight * 0.025),
                        // First row of two small containers
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
                            ),
                            SizedBox(width: screenWidth * 20 / 398),
                            Container(
                              width: (screenWidth - 2 * screenWidth * 28 / 398 - screenWidth * 20 / 398) / 2,
                              height: screenHeight * 148 / 866,
                              decoration: BoxDecoration(
                                color: Colors.white,
                                borderRadius: BorderRadius.circular(screenWidth * 0.057),
                              ),
                            ),
                            SizedBox(width: screenWidth * 28 / 398),
                          ],
                        ),
                        SizedBox(height: screenHeight * 0.025),
                        // Second row of two small containers
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
                            ),
                            SizedBox(width: screenWidth * 20 / 398),
                            Container(
                              width: (screenWidth - 2 * screenWidth * 28 / 398 - screenWidth * 20 / 398) / 2,
                              height: screenHeight * 148 / 866,
                              decoration: BoxDecoration(
                                color: Colors.white,
                                borderRadius: BorderRadius.circular(screenWidth * 0.057),
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