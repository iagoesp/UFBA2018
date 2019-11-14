
import os
import multiprocessing
import re
import subprocess
import signal

hasCompilerInternalError = False

def GetChildrenPids(ppid):
    outOfMemoryCmd = 'pgrep -P' + str(ppid)
    p = subprocess.Popen(outOfMemoryCmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, close_fds=True)
    output = p.stdout.read()
    return output.splitlines()

def Make(processCount):
    global hasCompilerInternalError
    p = subprocess.Popen(["make", "-j" + str(processCount)], shell=False, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    while p.poll() is None:
        # "make" process is still alive
        outline = str(p.stdout.readline())
        print(outline)
        internalError = re.findall(r"internal compiler error", outline)
        if len(internalError) is 0:
            internalError = re.findall(r"out of memory allocating", outline)
        if len(internalError) is not 0:
            hasCompilerInternalError = True
            gppPids = GetChildrenPids(p.pid)
            for gppPid in gppPids:
                compiler = GetChildrenPids(int(gppPid))
                print("Encounter an internal compiler error: kill compiler instance pid=" + str(compiler[0]))
                os.kill(int(compiler[0]), signal.SIGKILL)
            p.kill()
            p.wait()
            return
    p.wait()

processCount = multiprocessing.cpu_count() + 1
Make(processCount)
if hasCompilerInternalError:
    print("#### Multi-process compiliation failed: encounter an internal compiler error, try to build with single process ####")
    Make(1)
