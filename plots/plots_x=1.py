import numpy as np
import matplotlib.pyplot as plt

styles = {
    "bisection_x=1": dict(color="red",   marker="o", linestyle=":",  markerfacecolor="red"),
    "secant_x=1":    dict(color="blue",  marker="o", linestyle="--", markerfacecolor="none"),
    "newton_x=1":    dict(color="black", marker="x", linestyle="--"),
}

plt.figure(figsize=(5, 4))
for name, st in styles.items():
    d = np.loadtxt(f"data/{name}.csv", delimiter=",")
    plt.plot(d[:, 0], d[:, 3], markersize=5, linewidth=0.8, label=name.capitalize(), **st)
plt.yscale("log")
plt.xlim(0, 30)
plt.ylim(1e-16, 1)
plt.title("root x = 1")
plt.xlabel("iteration")
plt.ylabel(r"$\Delta = x_{k+1} - x_k$")
plt.legend()
plt.savefig("plots/delta_root1.png", dpi=200, bbox_inches="tight")

plt.figure(figsize=(5, 4))
for name, st in styles.items():
    d = np.loadtxt(f"data/{name}.csv", delimiter=",")
    plt.plot(d[:, 0], d[:, 1], markersize=5, linewidth=0.8, label=name.capitalize(), **st)
plt.xlim(0, 10)
plt.xticks(range(1, 11))
plt.ylim(0.4, 1.2)
plt.title("root x = 1")
plt.xlabel("iteration")
plt.ylabel(r"$x_k$")
plt.legend()
plt.savefig("plots/root1.png", dpi=200, bbox_inches="tight")