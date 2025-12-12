import 'package:flutter/material.dart';

class CustomSwitch extends StatelessWidget {
  final bool value;
  final Function(bool) onChanged;
  final double top;
  final double left;
  final double width;
  final double height;
  final Color activeColor;
  final Color inactiveColor;
  final Color thumbColor;
  final Color textColor;
  final String onText;
  final String offText;
  final double fontSize;
  final Function()? onLongPress;

  const CustomSwitch({
    Key? key,
    required this.value,
    required this.onChanged,
    required this.top,
    required this.left,
    this.width = 80,
    this.height = 40,
    this.activeColor = const Color(0xFF5DAFB8),
    this.inactiveColor = Colors.black,
    this.thumbColor = Colors.white,
    this.textColor = Colors.white,
    this.onText = 'ON',
    this.offText = 'OFF',
    this.fontSize = 14,
    this.onLongPress,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    double padding = height * 0.1;
    double thumbSize = height - (padding * 2);

    return Positioned(
      top: top,
      left: left,
      child: GestureDetector(
        onLongPress: onLongPress,
        onTap: () {
          onChanged(!value);
        },
        child: Container(
          width: width,
          height: height,
          decoration: BoxDecoration(
            color: value ? activeColor : inactiveColor,
            borderRadius: BorderRadius.circular(height / 2),
          ),
          child: Stack(
            children: [
              AnimatedPositioned(
                duration: Duration(milliseconds: 250),
                curve: Curves.easeInOut,
                left: value ? width - thumbSize - padding : padding,
                top: padding,
                child: Container(
                  width: thumbSize,
                  height: thumbSize,
                  decoration: BoxDecoration(
                    color: thumbColor,
                    shape: BoxShape.circle,
                  ),
                ),
              ),
              Center(
                child: Padding(
                  padding: EdgeInsets.only(
                    left: value ? 0 : thumbSize + padding + (width * -0.03),
                    right: value ? thumbSize + padding : 0,
                  ),
                  child: Text(
                    value ? onText : offText,
                    style: TextStyle(
                      color: textColor,
                      fontSize: fontSize,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
