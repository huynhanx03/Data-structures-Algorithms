"""
 Problem: 3721. Count Mentions Per User
 Language: python3
 Runtime: 51 ms (30.07%)
 Memory: 18 MB (80.42%)
 Tags: Array, Math, Sorting, Simulation
"""
class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        mentions = [0] * numberOfUsers
        online = [True] * numberOfUsers
        pq = []

        events.sort(key=lambda e: (int(e[1]), 0 if e[0] == "OFFLINE" else 1))

        for e in events:
            t = int(e[1])
            while pq and pq[0][0] <= t:
                _, uid = heapq.heappop(pq)
                online[uid] = True

            if e[0] == "OFFLINE":
                uid = int(e[2])
                online[uid] = False
                heapq.heappush(pq, (t + 60, uid))
            else:
                tokens = e[2].split()
                for token in tokens:
                    if token == "ALL":
                        for i in range(numberOfUsers):
                            mentions[i] += 1
                    elif token == "HERE":
                        for i in range(numberOfUsers):
                            if online[i]:
                                mentions[i] += 1
                    elif token.startswith("id"):
                        uid = int(token[2:])
                        if 0 <= uid < numberOfUsers:
                            mentions[uid] += 1

        return mentions