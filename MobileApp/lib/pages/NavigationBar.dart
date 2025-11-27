import 'package:flutter/material.dart';
import 'package:smart_homr/pages/security_page.dart';
import 'home_page.dart';
import 'lighting_Page.dart';

class AppNavigationBar extends StatefulWidget {
  const AppNavigationBar({super.key});

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

  final List<Widget> _pages = [
    const HomePage(),
    const LightingPage(),
    const SecurityPage(),
  ];

  @override
  Widget build(BuildContext context) {
    final screenWidth = MediaQuery.of(context).size.width;
    final screenHeight = MediaQuery.of(context).size.height;

    final sidePadding = screenWidth * (75 / 398);
    final iconSize = screenWidth * (30 / 398);
    final bottomPadding = screenHeight * (20 / 866);
    final topPadding = screenHeight * (15 / 866);
    final betweenSpacing = screenWidth * (75 / 398);

    return Scaffold(
      body: _pages[_selectedIndex],
      bottomNavigationBar: Container(
        height: kBottomNavigationBarHeight + topPadding + bottomPadding,
        padding: EdgeInsets.only(
          bottom: bottomPadding,
          top: topPadding,
        ),
        decoration: const BoxDecoration(
          color: Colors.transparent,
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            SizedBox(width: sidePadding),
            _buildNavItem(0, Icons.home, iconSize),
            SizedBox(width: betweenSpacing),
            _buildNavItem(1, Icons.lightbulb, iconSize),
            SizedBox(width: betweenSpacing),
            _buildNavItem(2, Icons.security, iconSize),
            SizedBox(width: sidePadding),
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