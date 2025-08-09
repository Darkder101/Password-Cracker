# 🛠️ Roadmap to Build the Tool & the Updates

⚠️ **Warning**: This tool is under active development.  
The following is a list of planned updates and improvements.  
Feel free to contribute by implementing any feature from the list!  

---

## ⚖️ Disclaimer  

> **This project is created strictly for educational and research purposes** to demonstrate how password cracking techniques work in a controlled, legal environment.  
> **Do not** use this tool for unauthorized access to systems, networks, or accounts.  
> Any misuse of this code may violate applicable laws and could result in severe penalties.  
> The author takes **no responsibility** for any illegal or unethical use of this tool.  
> Always ensure you have **explicit permission** before testing security on any system.  

---

## ✅ Phase 1: Offline Cracking Basics  
1. Basic Brute Force (Alphabets only, fixed length)  
2. Dictionary Attack (from file)  
3. Hash Comparison (MD5/SHA1/SHA256 using OpenSSL or own implementation)  

---

## 🔜 Phase 2: Advanced Offline Cracking  
1. Hybrid Attack (Append/prepend numbers to words)  
2. Rainbow Table Lookup (build and search simple rainbow tables)  
3. Rule-based Attacks (basic rules like capitalization, 1337 speak)  

💡 **Add Hash Formats:** bcrypt, NTLM  

---

## 🔜 Phase 3: Online Cracking Engine  
1. Basic HTTP Login Brute Force (test dummy web server locally)  
2. Credential Stuffing with Proxy Support  
3. FTP/SSH Brute Force using libraries like libssh or raw sockets  
4. Password Spraying Logic  
5. Phishing Simulation with Key Capture  

---
