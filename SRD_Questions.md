# Baby Pulse Oximeter Firmware Engineer Quiz

## Instructions

Answer the 50 multiple-choice questions below. Select the best answer for each question

---

## Section 1: System Overview & Components

1. What are the two main components of the baby pulse oximeter system?  
   - A. Sensor and Cloud Server  
   - B. Baby Sock and Base Station  
   - C. Base Station and Mobile App  
   - D. Transmitter and USB Charger  

2. What is the primary function of the baby sock?  
   - A. Display readings  
   - B. Transmit Wi-Fi data  
   - C. Measure SpO₂ and heart rate  
   - D. Generate alerts  

3. What is the role of the base station?  
   - A. Only stores data  
   - B. Measures heart rate  
   - C. Receives, processes, and transmits data  
   - D. Charges the baby sock  

4. In which environments is the system designed to operate?  
   - A. Only in hospitals  
   - B. Industrial environments  
   - C. Home and clinical settings  
   - D. Outdoor monitoring  

---

## Section 2: Hardware Components

5. Which sensor is used for SpO₂ and heart rate measurement?  
   - A. MAX30205  
   - B. MAX30102  
   - C. AD8232  
   - D. MLX90614  

6. What is the main role of the Nordic SoC (nRF52/53)?  
   - A. Cloud communication  
   - B. BLE communication and data processing  
   - C. Audio alert generation  
   - D. Power regulation  

7. Which component provides Wi-Fi connectivity in the base station?  
   - A. nRF52840  
   - B. MAX30102  
   - C. ESP32  
   - D. STM32  

8. What powers both the baby sock and the base station?  
   - A. Alkaline battery  
   - B. USB only  
   - C. Li-Ion battery  
   - D. Coin cell  

9. What is the purpose of the USB-C port on the base station?  
   - A. Debugging interface  
   - B. BLE pairing  
   - C. Charging  
   - D. Data logging  

10. Which component generates audible alerts for abnormal readings?  
    - A. LED indicator  
    - B. Buzzer  
    - C. ESP32  
    - D. MAX30102  

---

## Section 3: Functional & Performance Requirements

11. What is the specified SpO₂ measurement range?  
    - A. 80–100%  
    - B. 60–100%  
    - C. 70–100%  
    - D. 50–100%  

12. What accuracy is required for SpO₂ measurements?  
    - A. ±1%  
    - B. ±2%  
    - C. ±5%  
    - D. ±10%  

13. What heart rate range must the device support?  
    - A. 30–150 BPM  
    - B. 50–200 BPM  
    - C. 30–250 BPM  
    - D. 60–180 BPM  

14. What accuracy is required for heart rate measurements?  
    - A. ±1 BPM  
    - B. ±2 BPM  
    - C. ±5 BPM  
    - D. ±10 BPM  

15. What is the minimum BLE range between sock and base station?  
    - A. 5 meters  
    - B. 10 meters  
    - C. 15 meters  
    - D. 20 meters  

16. What minimum sampling rate is required for the MAX30102 sensor?  
    - A. 10 Hz  
    - B. 25 Hz  
    - C. 50 Hz  
    - D. 100 Hz  

17. How long must the baby sock operate on a single charge?  
    - A. 8 hours  
    - B. 12 hours  
    - C. 24 hours  
    - D. 48 hours  

18. What is the maximum allowable response time for alerting abnormal readings?  
    - A. 1 second  
    - B. 3 seconds  
    - C. 5 seconds  
    - D. 10 seconds  

---

## Section 4: Firmware & RTOS

19. Which operating system is used for firmware task management?  
    - A. Zephyr  
    - B. FreeRTOS  
    - C. ThreadX  
    - D. Mbed OS  

20. Which of these synchronization primitives are used in the firmware?  
    - A. Polling loops  
    - B. Interrupt chaining  
    - C. Semaphores, mutexes, and message queues  
    - D. Timers  

21. Which algorithm is used to calculate SpO₂?  
    - A. Kalman filter  
    - B. Ratio-of-ratios method  
    - C. FFT  
    - D. Moving average  

22. What is the bandpass filter range for heart rate detection?  
    - A. 0.1–5 Hz  
    - B. 0.5–10 Hz  
    - C. 1–20 Hz  
    - D. 5–15 Hz  

23. Dynamic calibration algorithms adjust for which factors?  
    - A. Battery voltage and temperature  
    - B. Sampling rate and BLE signal  
    - C. Skin tone, ambient light, and motion  
    - D. PCB temperature and humidity  

24. Which method is used for noise reduction in signal processing?  
    - A. Bandpass filter  
    - B. Moving average  
    - C. Kalman filter  
    - D. FFT  

---

## Section 5: Communication Protocols

25. Which BLE version is specified for sock-to-base station communication?  
    - A. BLE 4.0  
    - B. BLE 4.2  
    - C. BLE 5.0  
    - D. BLE Mesh  

26. Which Wi-Fi standard is used for base station-to-cloud connectivity?  
    - A. 802.11a  
    - B. 802.11ac  
    - C. 802.11 b/g/n  
    - D. 802.11ax  

27. What mechanism ensures data integrity in the transmitted packets?  
    - A. CRC32  
    - B. Checksums  
    - C. Parity bits  
    - D. AES encryption  

28. Which protocol secures data transmission from the base station to the cloud?  
    - A. HTTP  
    - B. FTP  
    - C. HTTPS  
    - D. MQTT  

---

## Section 6: Regulatory & Safety

29. What FDA classification applies to this device?  
    - A. Class I  
    - B. Class II  
    - C. Class III  
    - D. Not regulated  

30. Which standard covers medical electrical safety?  
    - A. ISO 13485  
    - B. IEC 60601-1  
    - C. ISO 10993  
    - D. IEC 62304  

31. Which standard ensures biocompatibility of skin-contact materials?  
    - A. ISO 9001  
    - B. ISO 10993  
    - C. IEC 60601-1  
    - D. FDA 21 CFR Part 11  

32. Which standard covers electromagnetic compatibility (EMC) testing?  
    - A. IEC 60601-1-2  
    - B. ISO 14971  
    - C. FCC Part 15  
    - D. EN 55032  

---

## Section 7: User Interface & Alerts

33. What triggers visual and audible alerts?  
    - A. BLE disconnection  
    - B. Abnormal SpO₂ or heart rate  
    - C. Low battery  
    - D. Wi-Fi disconnection  

34. What is the primary purpose of the cloud dashboard?  
    - A. OTA firmware updates  
    - B. Remote data access and alerts  
    - C. BLE pairing  
    - D. Device calibration  

35. What requirement applies to the base station’s local display?  
    - A. OLED technology  
    - B. Touchscreen interface  
    - C. Clear and intuitive readout  
    - D. Color depth ≥24 bit  

36. Which thresholds are configurable by the user?  
    - A. SpO₂ only  
    - B. Heart rate only  
    - C. Both visual (LED) and audible (buzzer) alerts  
    - D. None  

---

## Section 8: Testing & Validation

37. What does unit testing validate?  
    - A. Entire system functionality  
    - B. Cloud connectivity  
    - C. Individual components  
    - D. Regulatory compliance  

38. What is the goal of integration testing?  
    - A. Verify sensor accuracy  
    - B. Test BLE range  
    - C. Ensure seamless communication between components  
    - D. Validate user interface  

39. What does performance testing confirm?  
    - A. BLE throughput  
    - B. SpO₂ and heart rate accuracy under various conditions  
    - C. Battery charging time  
    - D. PCB layout robustness  

40. What is verified during battery life testing?  
    - A. Charging circuit stability  
    - B. 24-hour operation on a single charge  
    - C. USB-C port durability  
    - D. Power spike tolerance  

41. What does regulatory testing include?  
    - A. Only EMC tests  
    - B. Only safety tests  
    - C. Only biocompatibility tests  
    - D. Safety, EMC, and biocompatibility tests  

---

## Section 9: Development Lifecycle

42. What is the first step in the development process?  
    - A. Implementation  
    - B. Testing and validation  
    - C. Requirements gathering  
    - D. Manufacturing  

43. Which phase follows system design?  
    - A. Regulatory approval  
    - B. Implementation  
    - C. Cloud integration  
    - D. Post-market surveillance  

44. What is typically the final step before product launch?  
    - A. Cloud dashboard deployment  
    - B. Regulatory approval  
    - C. PCB fabrication  
    - D. BLE optimization  

45. Which phase includes post-market surveillance?  
    - A. Requirements gathering  
    - B. Testing and validation  
    - C. Manufacturing and launch  
    - D. System design  

---

## Section 10: Scenario-Based & Advanced

46. If BLE range unexpectedly drops below 10 m, what is a likely cause?  
    - A. Incorrect sampling rate  
    - B. EMI from PCB layout  
    - C. Faulty MAX30102 sensor  
    - D. Low battery  

47. How would you reduce motion artifacts in SpO₂ readings?  
    - A. Increase sampling rate only  
    - B. Apply bandpass filters and dynamic calibration  
    - C. Disable averaging algorithms  
    - D. Reduce BLE transmission frequency  

48. Which mechanism prevents race conditions in FreeRTOS?  
    - A. Software delays  
    - B. Mutexes  
    - C. Interrupt nesting  
    - D. Timers  

49. What’s the best practice for BLE and Wi-Fi coexistence?  
    - A. Use separate antennas and time-division scheduling  
    - B. Increase transmit power on both radios  
    - C. Disable BLE when Wi-Fi is active  
    - D. Move radios to different PCBs  

50. How do you handle ambient-light interference in SpO₂ measurements?  
    - A. Use dynamic calibration algorithms  
    - B. Increase the LED drive current  
    - C. Disable filters during bright light  
    - D. Reduce sensor sampling rate  

---

## Answer Key

1. B  
2. C  
3. C  
4. C  
5. B  
6. B  
7. C  
8. C  
9. C  
10. B  
11. C  
12. B  
13. C  
14. B  
15. B  
16. B  
17. C  
18. C  
19. B  
20. C  
21. B  
22. B  
23. C  
24. A  
25. C  
26. C  
27. B  
28. C  
29. B  
30. B  
31. B  
32. A  
33. B  
34. B  
35. C  
36. C  
37. C  
38. C  
39. B  
40. B  
41. D  
42. C  
43. B  
44. B  
45. C  
46. B  
47. B  
48. B  
49. A  
50. A
