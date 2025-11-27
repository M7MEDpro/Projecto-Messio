import 'package:flutter/material.dart';
import 'CustomAppBar.dart';

class LightingPage extends StatefulWidget {
  const LightingPage({super.key});

  @override
  State<LightingPage> createState() => _LightingPageState();
}

class _LightingPageState extends State<LightingPage> {
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
          width: screenWidth,
          decoration: const BoxDecoration(
            color: Color(0xFFDBE2EF),
            borderRadius: BorderRadius.only(
              bottomLeft: Radius.circular(40.5),
              bottomRight: Radius.circular(40.5),

            ),
          ),
        ),
      ),
    );
  }
}
