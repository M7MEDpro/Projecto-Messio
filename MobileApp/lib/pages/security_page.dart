import 'package:flutter/material.dart';

import 'CustomAppBar.dart';

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
