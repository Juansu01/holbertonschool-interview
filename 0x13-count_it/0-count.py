#!/usr/bin/python3
"""
Interview practice
"""

import requests


def count_words(subreddit, word_list, after=None, directory=None):
    """
    Queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords.
    """

    if directory is None:
        directory = dict()
        for word in word_list:
            directory[word] = 0

    if after is None:
        word_list = [[key, value] for key, value in directory.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))

        for wor in word_list:
            print(type(wor[1]))
            if wor[1]:
                print("{}: {}".format(wor[0].lower(), wor[1]))

        return None

    reddit_string = "https://www.reddit.com/"
    url = "{}r/{}/hot/.json".format(reddit_string, subreddit)
    params = {'limit': 100, 'after': after}
    head = {'user-agent': 'my-app/0.0.1'}

    res = requests.get(url, headers=head, params=params, allow_redirects=False)

    if res.status_code != 200:
        return None

    try:
        json = res.json()
    except Exception:
        return None

    try:
        data = json.get()
        after, children = data.get("after"), data.get("children")

        for child in children:
            title, post = child.get("title"), child.get("data")
            to_lower = [string.lower() for string in title.split(' ')]

            for word in word_list:
                directory[word] += to_lower.count(word.lower())
    except Exception:
        return None

    count_words(subreddit, word_list, after, directory)
