import subprocess

processes = []
n = 10
for i in range(n):
	with open(f"output_{i}", "w") as f:
		p = subprocess.Popen(['./Ex2/hello.exe', str(i)], stdout=f)
		processes.append(p)
for p in processes:
	p.wait()
print("Jobs complete!")
