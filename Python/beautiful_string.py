S = input()

ans_dict = {}
for i in S:
  try:
    ans_dict[i] += 1
  except KeyError:
    ans_dict[i] = 1

count_dict = {}
for k in ans_dict:
  try:
    count_dict[ans_dict[k]] += 1
  except:
    count_dict[ans_dict[k]] = 1

key_list = []
for k in count_dict:
  key_list.append(k)

if (len(key_list) == 1):
  print ('YES')
elif (len(key_list) >= 3):
  print ('NO')
else:
  if (count_dict[min(key_list)] == 1):
    print ('YES')
  elif (count_dict[max(key_list)] == 1):
    print ('YES')
  else:
    print ('NO')

print (ans_dict)
print (count_dict)
print (key_list)