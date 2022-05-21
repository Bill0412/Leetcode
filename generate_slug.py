

def generate_slug(name: str) -> str:
    """
    Generate a slug from a leetcode problem name
    """
    return '_'.join(name.replace('.', '').lower().split())


if __name__ == '__main__':
    # get problem name from user
    import sys
    if len(sys.argv) == 2:
        name = sys.argv[1]
    else:
        l = list()
        for i in range(1, len(sys.argv)):
            word = str(sys.argv[i])
            l.append(word)
        name = ' '.join(l)
        
    print(generate_slug(name))

