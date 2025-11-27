import 'package:flutter/material.dart';

import 'CustomAppBar.dart';

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
      appBar: const CustomAppBar(
        title: "WELCOME HOME",
        subtitle: "ABDO",
      ),
      body: Center(
        child: Container(
          height: screenHeight * 0.765,
          decoration: BoxDecoration(
            color: const Color(0xFFDBE2EF),
            borderRadius: const BorderRadius.only(
              bottomLeft: Radius.circular(40.5),
              bottomRight: Radius.circular(40.5),
            ),
          ),
          child: Column(
            children: [
              SizedBox(height: screenHeight * 0.138),
              Container(
                height: screenHeight * 0.153,
                width: screenWidth * 0.851,
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(36),
                ),
              ),
              SizedBox(height: screenHeight * 0.027),
              Column(
                children: [
                  Row(
                    children: [
                      SizedBox(width: screenWidth * 0.027),
                      Expanded(
                        child: Container(
                          height: screenHeight * 0.153,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius: BorderRadius.circular(22.5),
                          ),
                        ),
                      ),
                      SizedBox(width: screenWidth * 0.063),
                      Expanded(
                        child: Container(
                          height: screenHeight * 0.153,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius: BorderRadius.circular(22.5),
                          ),
                        ),
                      ),
                      SizedBox(width: screenWidth * 0.027),
                    ],
                  ),
                  SizedBox(height: screenHeight * 0.027),
                  Row(
                    children: [
                      SizedBox(width: screenWidth * 0.027),
                      Expanded(
                        child: Container(
                          height: screenHeight * 0.153,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius: BorderRadius.circular(22.5),
                          ),
                        ),
                      ),
                      SizedBox(width: screenWidth * 0.063),
                      Expanded(
                        child: Container(
                          height: screenHeight * 0.153,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius: BorderRadius.circular(22.5),
                          ),
                        ),
                      ),
                      SizedBox(width: screenWidth * 0.027),
                    ],
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );}
}