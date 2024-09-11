from bs4 import BeautifulSoup
import requests


html_text= requests.get("https://www.timesjobs.com/candidate/job-search.html?searchType=personalizedSearch&from=submit&searchTextSrc=&searchTextText=&txtKeywords=python&txtLocation=").text
soup = BeautifulSoup(html_text, 'lxml')

# Debugging: Print the entire HTML
#print(soup.prettify())

jobs = soup.find_all('li', class_='clearfix job-bx wht-shd-bx')

for job in jobs:
    # Find the li element within the ul
    li_element = job.find('ul', class_='top-jd-dtl clearfix').find('li')

    # Initialize an empty string to store the desired text
    experience = ''
    
    # Iterate through the contents of the li element
    for content in li_element.contents:
        # Check if the content is not an <i> tag and is of type NavigableString (text)
        if content.name != 'i':
            experience = content.strip()
    if '0' ==experience[0]:

        com_name = job.find('h3', class_='joblist-comp-name').text.strip()
        print(f'''\n{com_name}\n\n{experience}''')
        print('')