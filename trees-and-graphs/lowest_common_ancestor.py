def lowest_common_ancestor(root, v1, v2):
    if !root:
        return None
        if v1 < walk.val and v2 < walk.val:
            lowest_common_ancestor(root.left)
        if v1 > walk.val and v2 > walk.val:
            lowest_common_ancestor(root.right)
        else:
            return root.data


def lowest_common_ancestor(root, v1, v2):
    while root:
        if v1 < walk.val and v2 < walk.val:
            lowest_common_ancestor(root.left)
            if v1 > walk.val and v2 > walk.val:
                lowest_common_ancestor(root.right)
            else:
                return root.data

    return None
