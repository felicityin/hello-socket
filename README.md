# Build

```
cd src
gcc server.c -o server
gcc client.c -o client
```

# Run

```
$ ./server
[2] Recv: Hi, server! I'm client.
[3] Send: Hi, client!
[6] Close Socket
```

```
$ ./client
[1] Send: Hi, server! I'm client.
[4] Recv: Hi, client!
[5] Close Socket
```

# Tcpdump

```
$ sudo tcpdump -S -i any tcp port 8700

# The TCP three-way handshake
12:54:05.871674 IP localhost.51964 > localhost.8700: Flags [S], seq 1063616027, win 65495, options [mss 65495,sackOK,TS val 1327422536 ecr 0,nop,wscale 7], length 0
12:54:05.871700 IP localhost.8700 > localhost.51964: Flags [S.], seq 411719856, ack 1063616028, win 65483, options [mss 65495,sackOK,TS val 1327422536 ecr 1327422536,nop,wscale 7], length 0
12:54:05.871719 IP localhost.51964 > localhost.8700: Flags [.], ack 411719857, win 512, options [nop,nop,TS val 1327422536 ecr 1327422536], length 0

# Send / Recv data
12:54:05.871752 IP localhost.51964 > localhost.8700: Flags [P.], seq 1063616028:1063616052, ack 411719857, win 512, options [nop,nop,TS val 1327422536 ecr 1327422536], length 24
12:54:06.872172 IP localhost.8700 > localhost.51964: Flags [P.], seq 411719857:411719869, ack 1063616052, win 512, options [nop,nop,TS val 1327423537 ecr 1327422536], length 12
12:54:06.872180 IP localhost.51964 > localhost.8700: Flags [.], ack 411719869, win 512, options [nop,nop,TS val 1327423537 ecr 1327423537], length 0

# The TCP four-way wave
12:54:06.872206 IP localhost.51964 > localhost.8700: Flags [F.], seq 1063616052, ack 411719869, win 512, options [nop,nop,TS val 1327423537 ecr 1327423537], length 0
12:54:06.920068 IP localhost.8700 > localhost.51964: Flags [.], ack 1063616053, win 512, options [nop,nop,TS val 1327423585 ecr 1327423537], length 0
12:54:07.872281 IP localhost.8700 > localhost.51964: Flags [F.], seq 411719869, ack 1063616053, win 512, options [nop,nop,TS val 1327424537 ecr 1327423537], length 0
12:54:07.872293 IP localhost.51964 > localhost.8700: Flags [.], ack 411719870, win 512, options [nop,nop,TS val 1327424537 ecr 1327424537], length 0
```
