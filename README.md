# Pro-Micro-Air-Mouse
3D mouse based on Pro Micro and MPU6050.

There is a bug when cursor change its position without moving the mouse. This is because the MPU6050 does not count tilt angles correctly. It becomes significant when the sensitivity variable drops to 300.

To solve this problem you can raise the sensitivity or change the value of the error variable (or try to offer your own solution :)).
