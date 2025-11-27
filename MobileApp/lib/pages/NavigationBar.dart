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
    HomePage(),
    LightingPage(),
    SecurityPage(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: _pages[_selectedIndex],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _selectedIndex,
        onTap: _navigateBottomBar,
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.home), label: "Home"),
          BottomNavigationBarItem(icon: Icon(Icons.lightbulb), label: "Lighting"),
          BottomNavigationBarItem(icon: Icon(Icons.security), label: "Security"),
        ],selectedItemColor: Colors.green,

      ),
    );
  }
}
