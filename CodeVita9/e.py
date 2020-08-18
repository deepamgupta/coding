cost_herbi, cost_carni, cost_aquatic = map(int, input().split())
max_area_herbi, max_area_carni, max_area_aquatic = map(int, input().split())

min_herbi, min_area_herbi = map(int, input().split())
min_carni, min_area_carni = map(int, input().split())
min_aquatic, min_area_aquatic = map(int, input().split())

total_area = int(input())

temp_cost = min(cost_herbi, cost_carni, cost_aquatic)
if temp_cost == cost_herbi:
    area1 = max_area_herbi * temp_cost
    x = max_area_herbi
elif temp_cost == cost_carni:
    area1 = max_area_carni * temp_cost
    x = max_area_carni
else:
    area1 = max_area_aquatic * temp_cost
    x = max_area_aquatic

temp_cost = max(cost_herbi, cost_carni, cost_aquatic)
if temp_cost == cost_herbi:
    area2 = min_herbi * min_area_herbi * cost_herbi
    y = min_herbi * min_area_herbi
elif temp_cost == cost_carni:
    area2 = min_carni * min_area_carni * cost_carni
    y = min_carni * min_area_carni
else:
    area2 = min_aquatic * min_area_aquatic * cost_aquatic
    y = min_aquatic * min_area_aquatic

zoo_area = total_area - (x + y)
a = []
a.append(cost_herbi)
a.append(cost_carni)
a.append(cost_aquatic)
sorted_arr = sorted(a)
area3 = zoo_area * sorted_arr[1]

print(area1 + area2 + area3)



