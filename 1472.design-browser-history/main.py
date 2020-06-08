class BrowserHistory(object):

    def __init__(self, homepage):
        """
        :type homepage: str
        """
        self.hindex = 0
        self.history = [homepage]


    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        self.history[:] = self.history[:self.hindex+1]
        self.history.append(url)
        self.hindex += 1


    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        self.hindex -= min(steps, self.hindex)
        return self.history[self.hindex]


    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        self.hindex += min(steps, len(self.history) - self.hindex - 1)
        return self.history[self.hindex]
