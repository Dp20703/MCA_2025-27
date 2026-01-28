import hashlib

# Input string
text1 = "Hello, World!"

# Encode string to bytes (hash functions need bytes)
encoded_text = text1.encode()

# Generate different hashes
md5_hash = hashlib.md5(encoded_text).hexdigest()
sha1_hash = hashlib.sha1(encoded_text).hexdigest()
sha256_hash = hashlib.sha256(encoded_text).hexdigest()

# Display results
print("Original Text:", text1)
print("MD5 Hash:    ", md5_hash)
print("SHA1 Hash:   ", sha1_hash)
print("SHA256 Hash: ", sha256_hash)

# Input string
text2 = "Hello"

# Encode string to bytes (hash functions need bytes)
encoded_text = text2.encode()

# Generate different hashes
md5_hash = hashlib.md5(encoded_text).hexdigest()
sha1_hash = hashlib.sha1(encoded_text).hexdigest()
sha256_hash = hashlib.sha256(encoded_text).hexdigest()

# Display results
print("Original Text:", text2)
print("MD5 Hash:    ", md5_hash)
print("SHA1 Hash:   ", sha1_hash)
print("SHA256 Hash: ", sha256_hash)

# Input string
text3 = "Hello."

# Encode string to bytes (hash functions need bytes)
encoded_text = text3.encode()

# Generate different hashes
md5_hash = hashlib.md5(encoded_text).hexdigest()
sha1_hash = hashlib.sha1(encoded_text).hexdigest()
sha256_hash = hashlib.sha256(encoded_text).hexdigest()

# Display results
print("Original Text:", text3)
print("MD5 Hash:    ", md5_hash)
print("SHA1 Hash:   ", sha1_hash)
print("SHA256 Hash: ", sha256_hash)
