# Salesforce Apex Code Execution Guide

This guide explains how to run Apex code in Salesforce using the **Developer Console**.

---

## Steps to Run Apex Code

### 1. Open Developer Console
- In Salesforce, click the **gear icon** → **Developer Console**.

### 2. Open Execute Anonymous Window
- Go to **Debug → Open Execute Anonymous Window**.

### 3. Paste Apex Code and Execute
- Copy the code below and paste it into the **Execute Anonymous Window**.
- Click **Execute**.

---

## Example: Geometry Area Calculator

#### Apex Class:

```apex
public class GeometryAreaCalculator {
    public static Decimal calculateCircleArea(Decimal radius) { return Math.PI * radius * radius; }
    public static Decimal calculateRectangleArea(Decimal length, Decimal width) { return length * width; }
    public static Decimal calculateTriangleArea(Decimal base, Decimal height) { return 0.5 * base * height; }
}
```

#### Steps to Run the Example:
1. Open the **Developer Console** in Salesforce.
2. Create a new Apex Class:
   - Go to **File → New → Apex Class**.
   - Name the class `GeometryAreaCalculator`.
   - Paste the above code into the class and save it.
3. Open the **Execute Anonymous Window**:
   - Go to **Debug → Open Execute Anonymous Window**.
4. Paste the following code into the Execute Anonymous Window to test the class:

```apex
Decimal circleArea = GeometryAreaCalculator.calculateCircleArea(5);
Decimal rectangleArea = GeometryAreaCalculator.calculateRectangleArea(10, 20);
Decimal triangleArea = GeometryAreaCalculator.calculateTriangleArea(10, 15);

System.debug('Circle Area: ' + circleArea);
System.debug('Rectangle Area: ' + rectangleArea);
System.debug('Triangle Area: ' + triangleArea);
```

5. Click **Execute**.
6. View the results in the **Logs** tab of the Developer Console.

---

## Output
After executing the code, you will see the calculated areas in the logs:
(Click on the 'Debug Only' checkbox below to filter out unnecessary logs)

```
Circle Area: 78.53981633974483
Rectangle Area: 200
Triangle Area: 75
```

This demonstrates how to use the `GeometryAreaCalculator` class to calculate areas for different shapes.