import 'package:flutter/material.dart';

class CustomAppBar extends StatelessWidget implements PreferredSizeWidget {
  final String title;
  final String subtitle;
  final double height;

  const CustomAppBar({
    super.key,
    required this.title,
    required this.subtitle,
    required this.height,
  });

  @override
  Widget build(BuildContext context) {
    final screenWidth = MediaQuery.of(context).size.width;
    final screenHeight = MediaQuery.of(context).size.height;

    return AppBar(
      backgroundColor: const Color(0xFFDBE2EF),
      elevation: 0,
      scrolledUnderElevation: 0,
      toolbarHeight: height,
      automaticallyImplyLeading: false,
      flexibleSpace: SafeArea(
        child: Padding(
          padding: EdgeInsets.only(
            top: screenHeight * 0.015,
            left: screenWidth * 0.05,
            right: screenWidth * 0.05,
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
                title,
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
                subtitle,
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
    );
  }

  @override
  Size get preferredSize => Size.fromHeight(height);
}