s = input()
words = {word: len(word) for word in s.split()}

maxLength = words[max(words, key=words.get)]

ans = ""

for i in range(0, maxLength):
    for word, wordLength in words.items():
        if i < wordLength:
            ans += word[i]

print(ans)
