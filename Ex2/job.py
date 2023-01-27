import subprocess

processes = []
n = 10
for i in range(10):
	with open(f"output_{i}", "w") as f:
		p = subprocess.Popen(['./Ex2/hello.exe', str(1)], stdout=f)
		processes.append(p)
for p in processes:
	p.wait()
print("Jobs complete!")
