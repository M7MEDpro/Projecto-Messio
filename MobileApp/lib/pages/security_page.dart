import 'package:flutter/material.dart';
import 'NavigationBar.dart';

class SecurityPage extends StatefulWidget {
  const SecurityPage({super.key});

  @override
  State<SecurityPage> createState() => _SecurityPageState();
}

class _SecurityPageState extends State<SecurityPage> {
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
      ),
    );
  }
}