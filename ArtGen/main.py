import requests
from bs4 import BeautifulSoup
import random

response = requests.get("https://www.asciiart.eu/animals/cats")
soup = BeautifulSoup(response.content, 'html.parser')

ascii_art_list = soup.find_all('pre')

random_ascii_art = random.choice(ascii_art_list).text

print(random_ascii_art)

input()