#! python3
# coding = utf-8
'''
# Created on Oct-27-19 22:36
# downloadPdfFromMooc.py
# @author: k1vin
#
# Description:
'''

import requests
import os
import bs4

url = 'https://www.icourse163.org/learn/NJU-1001625001?tid=1206622249#/learn/content?type=detail&id=1211390547&cid=1214042237'  # starting url

os.makedirs('temp html', exist_ok=True)  # store comics in ./xkcd

# Download the page.
print('Downloading page %s...' % url)

res = requests.get(url)
res.raise_for_status()

markup = '''
<a class="j-downpdf downpdf u-btn u-btn-sm u-btn-whiteGreen f-fr" target="_blank" href="https://nos.netease.com/edu-lesson-pdfsrc/5E664F66CC57C030A1667F57FB291562-1467269834706?Signature=532IgstJZ0ZppCdPlvI7rdTrVyKmsqk%2FQJymTwQ64Zg%3D&amp;Expires=1572195408&amp;NOSAccessKeyId=7ba71f968e4340f1ab476ecb300190fa&amp;download=C%E8%AF%AD%E8%A8%80%E7%A8%8B%E5%BA%8F%E4%B8%BE%E4%BE%8B.pdf">文档下载</a>
'''
soup = bs4.BeautifulSoup(res.text, 'lxml')
# soup = bs4.BeautifulSoup(markup, 'lxml') debug
 
#TODO: wrong url
# Find the URL of the html
for aTag in soup.findAll('a',text="文档下载\n"):
    if aTag == []:
        print('Could not find tag.')
    else:
        print(aTag)
        # comicUrl = comicElem[0].get('src')
        # # Download the image.
        # print('Downloading image %s...' % (comicUrl))
        # res = requests.get(comicUrl)
        # res.raise_for_status()

        # Save the image to ./xkcd
        # imageFile = open(os.path.join(
        #     'xkcd', os.path.basename(comicUrl)), 'wb')
        # for chunk in res.iter_content(100000):
        #     imageFile.write(chunk)
        # imageFile.close()
