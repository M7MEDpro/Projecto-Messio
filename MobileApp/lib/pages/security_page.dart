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
        child : ListView(
          children: [
            Padding(
              padding:  EdgeInsets.all(screenHeight),
              child: Container(
                width: screenWidth*341/398,
                height: screenHeight*69/866,
                decoration: BoxDecoration(
                  color: Color(0xFFFFFFFF),
                  borderRadius: BorderRadius.circular(screenWidth*24/398),


                )

              ),
            )
          ],

        ),

      ),
    );
  }
}