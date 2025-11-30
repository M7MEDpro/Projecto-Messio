import 'package:flutter/material.dart';
import 'CustomAppBar.dart';

class SecurityPage extends StatefulWidget {
  const SecurityPage({super.key});

  @override
  State<SecurityPage> createState() => _SecurityPageState();
}

bool isHomeDoorClicked = true;
bool isGarageDoorClicked = false;

class _SecurityPageState extends State<SecurityPage> {
  String garageDoorStatus = "CLOSED";
  String homeDoorStatus = "CLOSED";

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
            Padding(
              padding: EdgeInsets.symmetric(
                  horizontal: screenWidth * 0.07,
                  vertical: screenHeight * 0.029),
              child: Container(
                width: screenWidth * 0.86,
                height: screenHeight * 0.08,
                decoration: BoxDecoration(
                  color: Color(0xFFFFFFFF),
                  borderRadius: BorderRadius.circular(screenWidth * 0.063),
                ),
                child: Row(
                  children: [
                    Expanded(
                      child: GestureDetector(
                        onTap: () {
                          setState(() {
                            isHomeDoorClicked = true;
                            isGarageDoorClicked = false;
                          });
                        },
                        child: Center(
                          child: Text(
                            "HOME DOOR",
                            style: TextStyle(
                              fontSize: screenWidth * 0.045,
                              fontWeight: FontWeight.w700,
                              color: isHomeDoorClicked
                                  ? Color(0xFF67B8C6)
                                  : Colors.black87,
                            ),
                          ),
                        ),
                      ),
                    ),
                    Container(
                      width: screenWidth * 0.004,
                      height: screenHeight * 0.047,
                      color: Colors.black26,
                    ),
                    Expanded(
                      child: GestureDetector(
                        onTap: () {
                          setState(() {
                            isGarageDoorClicked = true;
                            isHomeDoorClicked = false;
                          });
                        },
                        child: Center(
                          child: Text(
                            "GARAGE DOOR",
                            style: TextStyle(
                              fontSize: screenWidth * 0.045,
                              fontWeight: FontWeight.w700,
                              color: isGarageDoorClicked
                                  ? Color(0xFF67B8C6)
                                  : Colors.black87,
                            ),
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            Padding(
              padding: EdgeInsets.symmetric(horizontal: screenWidth * 27 / 398),
              child: Container(
                height: screenHeight * 342 / 866,
                width: screenWidth * 342 / 398,
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(screenWidth * 0.063),
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Container(
                      height: screenWidth * 0.6,
                      width: screenWidth * 0.62,
                      decoration: BoxDecoration(
                        borderRadius:
                        BorderRadius.circular(screenWidth * 0.05),
                      ),
                      child: ClipRRect(
                        borderRadius:
                        BorderRadius.circular(screenWidth * 0.05),
                        child: Image.asset(
                          isGarageDoorClicked
                              ? "assets/images/garage.png"
                              : "assets/images/mainDoor.png",
                          fit: BoxFit.cover,
                        ),
                      ),
                    ),
                    SizedBox(height: screenHeight * 0.02),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Text(
                          isGarageDoorClicked
                              ? garageDoorStatus
                              : homeDoorStatus,
                          style: TextStyle(
                            fontSize: screenWidth * 0.045,
                            fontWeight: FontWeight.w700,
                            color: Colors.black87,
                          ),
                        ),
                        SizedBox(width: screenWidth * 0.02),
                        Icon(
                          (isGarageDoorClicked
                              ? garageDoorStatus
                              : homeDoorStatus) ==
                              "CLOSED"
                              ? Icons.lock
                              : Icons.lock_open,
                          size: screenWidth * 0.05,
                          color: Colors.black87,
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
            SizedBox(height: screenHeight * 0.02),
            Padding(
              padding: EdgeInsets.symmetric(
                  horizontal: screenWidth * 0.07,
                  vertical: screenHeight * 0.01),
              child: Container(
                width: screenWidth * 0.86,
                height: screenHeight * 0.08,
                decoration: BoxDecoration(
                  color: Color(0xFFFFFFFF),
                  borderRadius: BorderRadius.circular(screenWidth * 0.063),
                ),
                child: Row(
                  children: [
                    Expanded(
                      child: GestureDetector(
                        onTap: () {
                          setState(() {
                            if (isGarageDoorClicked) {
                              garageDoorStatus = "CLOSED";
                            } else {
                              homeDoorStatus = "CLOSED";
                            }
                          });
                        },
                        child: Center(
                          child: Text(
                            "CLOSE",
                            style: TextStyle(
                              fontSize: screenWidth * 0.045,
                              fontWeight: FontWeight.w700,
                              color: (isGarageDoorClicked &&
                                  garageDoorStatus == "CLOSED") ||
                                  (!isGarageDoorClicked &&
                                      homeDoorStatus == "CLOSED")
                                  ? Color(0xFF67B8C6)
                                  : Colors.black87,
                            ),
                          ),
                        ),
                      ),
                    ),
                    Container(
                      width: screenWidth * 0.004,
                      height: screenHeight * 0.047,
                      color: Colors.black26,
                    ),
                    Expanded(
                      child: GestureDetector(
                        onTap: () {
                          setState(() {
                            if (isGarageDoorClicked) {
                              garageDoorStatus = "OPEN";
                            } else {
                              homeDoorStatus = "OPEN";
                            }
                          });
                        },
                        child: Center(
                          child: Text(
                            "OPEN",
                            style: TextStyle(
                              fontSize: screenWidth * 0.045,
                              fontWeight: FontWeight.w700,
                              color: (isGarageDoorClicked &&
                                  garageDoorStatus == "OPEN") ||
                                  (!isGarageDoorClicked &&
                                      homeDoorStatus == "OPEN")
                                  ? Color(0xFF67B8C6)
                                  : Colors.black87,
                            ),
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}