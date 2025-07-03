# 💻 Dynamic Operating System Simulation

This project is a simulation of an advanced Operating System environment, focusing on **hybrid process scheduling** and **real-time deadlock prevention** using **Banker’s Algorithm**. It is developed in **C++** for the **Operating Systems (CS-303)** course at HITEC University, Taxila.

---

## 🚀 Features

- 🔁 **Hybrid CPU Scheduling**:
  - Combines **Round Robin**, **Priority Scheduling**, and **Shortest Job Next (SJN)**
  - Dynamically switches based on system load

- ⚙️ **Deadlock Prevention**:
  - Uses **Banker’s Algorithm** to ensure system remains in a safe state
  - Visual representation via Resource Allocation Graph (RAG)

- ⏳ **Starvation Handling**:
  - Implements **Aging** to increase priority of long-waiting processes

- 📈 **Performance Metrics**:
  - Average waiting time
  - Turnaround time
  - Resource utilization

- 📊 **Visual Outputs**:
  - Gantt Chart for scheduling
  - RAG for deadlock detection

---

## 📂 Project Structure

---

## 🔧 Technologies Used

- **Language**: C++  
- **Concepts**:
  - Operating System Scheduling
  - Deadlock Detection and Prevention
  - Simulation and Visualization

---

## 📷 Screenshots

| Gantt Chart | RAG Diagram |
|-------------|-------------|
| ![Gantt Chart](outputs/gantt_chart.png) | ![RAG](outputs/resource_allocation_graph.png) |

---

## 🧠 Key Algorithms

- **Round Robin (RR)**  
- **Priority Scheduling**  
- **Shortest Job Next (SJN)**  
- **Banker’s Algorithm**  
- **Aging (for starvation prevention)**

---

## 📊 Performance Comparison

| Metric              | Without Hybrid Scheduling | With Hybrid Scheduling |
|---------------------|---------------------------|-------------------------|
| Avg Waiting Time    | High                      | Low                     |
| Turnaround Time     | High                      | Low                     |
| Starvation          | May Occur                 | Avoided (via Aging)     |
| Deadlock            | Possible                  | Prevented               |
| Resource Utilization| Poor                      | Optimized               |

---

## 👨‍💻 Contributors

- Hassan Ali – [23-CYS-035]
- Muneeb Ahmed – [23-CYS-004]  
- Syed Haider Abbas – [23-CYS-038]  
- Shayan Latif – [23-CYS-041]  


---

## 📚 References

- *Operating System Concepts* – Abraham Silberschatz  
- *Operating Systems: Internals and Design Principles* – William Stallings  
- [Banker's Algorithm – Wikipedia](https://en.wikipedia.org/wiki/Banker%27s_algorithm)  
- [Banker’s Algorithm – GeeksforGeeks](https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/)

---

## ✅ Conclusion

This project successfully demonstrates how **hybrid scheduling**, **aging**, and **Banker's Algorithm** can work together to simulate a stable and efficient OS environment. The system adapts dynamically to workloads while ensuring fairness and safety.

---


