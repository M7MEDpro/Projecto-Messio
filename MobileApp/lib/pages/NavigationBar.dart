import 'package:flutter/material.dart';
import 'package:smart_homr/pages/security_page.dart';
import 'home_page.dart';
import 'lighting_Page.dart';

class AppNavigationBar extends StatefulWidget {
  final String username;
  const AppNavigationBar({super.key, required this.username});

  @override
  State<AppNavigationBar> createState() => _AppNavigationBarState();
}

class _AppNavigationBarState extends State<AppNavigationBar> {
  int _selectedIndex = 0;

  void _navigateBottomBar(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }

  late final List<Widget> _pages;

  @override
  void initState() {
    super.initState();
    _pages = [
      HomePage(username: widget.username),
      LightingPage(username: widget.username),
      SecurityPage(username: widget.username),
    ];
  }

  @override
  Widget build(BuildContext context) {
    final screenWidth = MediaQuery.of(context).size.width;
    final screenHeight = MediaQuery.of(context).size.height;

    return Scaffold(
      body: _pages[_selectedIndex],
      bottomNavigationBar: Container(
        height: kBottomNavigationBarHeight + (screenHeight * 0.017) + (screenHeight * 0.023),
        padding: EdgeInsets.only(
          bottom: screenHeight * 0.023,
          top: screenHeight * 0.017,
          left: screenWidth * 0.05,
          right: screenWidth * 0.05,
        ),
        decoration: const BoxDecoration(
          color: Colors.transparent,
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            _buildNavItem(0, Icons.home, screenWidth * 0.075),
            _buildNavItem(1, Icons.lightbulb, screenWidth * 0.075),
            _buildNavItem(2, Icons.security, screenWidth * 0.075),
          ],
        ),
      ),
    );
  }

  Widget _buildNavItem(int index, IconData icon, double iconSize) {
    return Expanded(
      child: GestureDetector(
        onTap: () => _navigateBottomBar(index),
        child: Container(
          constraints: const BoxConstraints(
            minHeight: 0,
            maxHeight: kBottomNavigationBarHeight,
          ),
          decoration: const BoxDecoration(
            color: Colors.transparent,
          ),
          child: Icon(
            icon,
            size: iconSize,
            color: _selectedIndex == index
                ? const Color(0xFF67B8C6)
                : const Color(0xFF000000),
          ),
        ),
      ),
    );
  }
}
