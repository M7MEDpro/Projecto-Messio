import 'package:flutter/material.dart';
class LightingPage extends StatefulWidget {
  const LightingPage({super.key});

  @override
  State<LightingPage> createState() => _LightingPageState();
}

class _LightingPageState extends State<LightingPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Lighting"),
        centerTitle: true,
      ),
      body: const Placeholder(),
    );
  }
}
