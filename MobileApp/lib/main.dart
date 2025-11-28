import 'package:flutter/material.dart';
import 'package:smart_homr/pages/CustomAppBar.dart';
import 'package:smart_homr/pages/NavigationBar.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: AppNavigationBar(),
    );

  }
}
