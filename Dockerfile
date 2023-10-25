FROM grantbot/xv6
WORKDIR /~/xv6-public/
COPY . .
CMD ["make", "r"]