from collections import Counter

# 입력 받기
word1 = input().strip()
word2 = input().strip()

# 각 알파벳 개수 세기
count1 = Counter(word1)
count2 = Counter(word2)

# 제거해야 하는 문자 수 계산
remove_count = 0
for ch in set(count1.keys()) | set(count2.keys()):
    remove_count += abs(count1.get(ch, 0) - count2.get(ch, 0))

print(remove_count)
